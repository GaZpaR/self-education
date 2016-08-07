#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

using boost::asio::ip::tcp;

typedef struct{
	uint clientid;
	std::string datetime;
	std::string p1;
	std::string p2;
	std::string p3;
	std::string p4;
}MESS;

void writexml(std::shared_ptr<std::vector<MESS>> &b){
	
};

std::shared_ptr<std::vector<MESS>> cb, pb;

void parser(std::string str, const uint maxlen){

	if(cb->size() < maxlen){
		// Writing in current buffer
	}
	else{
		// Changing current buffer and writing mess to the new buffer
		std::shared_ptr<std::vector<MESS>> tp;
		tp = cb;
		cb = pb;
		pb = tp;

		// Generating thread to write previous buffer to the disk
		// and erase it
		boost::thread t(boost::bind(writexml, pb));
		t.detach();
		parser(str, maxlen);
	}
}

//	time_t t = time(NULL);
//	struct tm tm = *localtime(&t);

//	printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
//
const int max_length = 1024;

typedef boost::shared_ptr<tcp::socket> socket_ptr;

void session(socket_ptr sock)
{
	try{
		for (;;){
			char data[max_length];

			boost::system::error_code error;
			size_t length = sock->read_some(boost::asio::buffer(data), error);
			if (error == boost::asio::error::eof)
				break; // Connection closed cleanly by peer.
			else if (error)
						throw boost::system::system_error(error); // Some other error.



			boost::asio::write(*sock, boost::asio::buffer(data, length));
			sock->close(error);
			if(error){
				std::cout << "Can't close socket" << std::endl;
			}
			else break;
		}
	}
	catch (std::exception& e)	{
		std::cerr << "Exception in thread: " << e.what() << "\n";
	}
}

void server(boost::asio::io_service& io_service, short port)
{
	tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), port));
	for (;;){
		socket_ptr sock(new tcp::socket(io_service));
		a.accept(*sock);
		boost::thread t(boost::bind(session, sock));
	}
}

int main(int argc, char* argv[])
{
	try{
		if (argc != 2){
			std::cerr << "Usage: blocking_tcp_echo_server <port>\n";
			return 1;
		}

		boost::asio::io_service io_service;

		using namespace std; // For atoi.
		server(io_service, atoi(argv[1]));
	}
	catch (std::exception& e){
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
