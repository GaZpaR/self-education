#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

#include "server.hpp"

boost::mutex tbuf, wrbuf;

using boost::asio::ip::tcp;

typedef struct{
	std::string clientid;
	std::string datetime;
	std::string p1;
	std::string p2;
	std::string p3;
	std::string p4;
}MESS;

std::vector<MESS> cb, pb, *buffer = &cb;

boost::shared_ptr<bool> bufswitch(new bool);

void writexml(std::vector<MESS> &b){
	wrbuf.lock();
	b.erase(b.begin(), b.end());
	wrbuf.unlock();
};

void writeRestMessages(){
	tbuf.lock();

	tbuf.unlock();
}

void parser(std::string &str, const uint maxlen){
	MESS curmes;
	time_t now = std::time(0);
 	curmes.datetime = std::ctime(&now);

	bool flag; 

	tbuf.lock();
	if(buffer->size() < maxlen) flag = true;
	else flag = false;
	tbuf.unlock();

	if(flag){
		// Writing in current buffer
		uint j = 0;

		for(uint i=0; i<str.length(); i++){
			if(str[i] == '#') j = i;
				// Message start
			if(str[i] == ','){
				// Client ID
				curmes.clientid.assign(str, j+1, i-j-1);
				j = i+1;
				break;
			}
		}
	
		for(uint i=j; i<str.length(); i++){
			if(str[i] == ','){
				// P1
				curmes.p1.assign(str, j, i-j);
				j = i+1;
				break;
			}
		}
		for(uint i=j; i<str.length(); i++){
			if(str[i] == ','){
				// P2
				curmes.p2.assign(str, j, i-j);
				j = i+1;
				break;
			}
		}
		for(uint i=j;i <str.length(); i++){
			if(str[i] == ','){
				// P3
				curmes.p3.assign(str, j, i-j);
				j = i+1;
				break;
			}
		}
		for(uint i=j;i <str.length(); i++){
			if(str[i] == '$'){
				// P4
				curmes.p4.assign(str, j, i-j);
				break;
			}
		}
		std::cout << "Client ID: " << curmes.clientid << std::endl;
		std::cout << "Current time: " << curmes.datetime;
		std::cout << "P1: " << curmes.p1 << std::endl;
		std::cout << "P2: " << curmes.p2 << std::endl;
		std::cout << "P3: " << curmes.p3 << std::endl;
		std::cout << "P4: " << curmes.p4 << std::endl;

		tbuf.lock();
		buffer->push_back(curmes);
		tbuf.unlock();
	}
	else{
		// Changing current buffer and writing mess to the new buffer
		tbuf.lock();
		wrbuf.lock();
		std::vector<MESS> *tp = buffer;
		if(*bufswitch){
			buffer = &pb;
			*bufswitch = false;
		}
		else{
			buffer = &cb;
			*bufswitch = true;
		}
		tbuf.unlock();
		wrbuf.unlock();

		// Write previous buffer to the disk
		// and erase it
		writexml(*tp);
		parser(str, maxlen);
	}
}

const int max_length = 256;

typedef boost::shared_ptr<tcp::socket> socket_ptr;

void session(socket_ptr sock, const uint buflen)
{
	try{
			char data[max_length];

			boost::system::error_code error;
			size_t length = sock->read_some(boost::asio::buffer(data), error);
			if (error == boost::asio::error::eof)
				std::cout << "Connection closed cleanly by peer" << std::endl; 
			else if (error)
						throw boost::system::system_error(error); // Some other error.

			std::string s;
			s.assign(data, 0, length);
			parser(s, buflen);
			boost::asio::write(*sock, boost::asio::buffer(data, length));
/*			sock->close(error);
			if(error){
				std::cout << "Can't close socket" << std::endl;
			}*/
	}
	catch (std::exception& e)	{
		std::cerr << "Exception in thread: " << e.what() << "\n";
	}
}

void server(boost::asio::io_service& io_service, short port, const uint buflen)
{
	tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), port));
	for (;;){
		socket_ptr sock(new tcp::socket(io_service));
		a.accept(*sock);
		boost::thread t(boost::bind(session, sock, buflen));
	}
}

void startServer(const uint portNo, const uint buflen)
{
	try{
		boost::asio::io_service io_service;

		server(io_service, portNo, buflen);
	}
	catch (std::exception& e){
		std::cerr << "Exception: " << e.what() << "\n";
	}
}
