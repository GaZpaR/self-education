#include <iostream>
#include <fstream>
#include "tree.h"

INode* allocator(std::string exp){
	uint j=1;
	NC cs;

	// Allocating coordinates of Node
	for(uint i=0; i<exp.length(); i++){
		if(exp[i] == '.'){
			std::string t;
			t.assign(exp, j, i-1);

			cs.lev = std::stoi(t);
			j = i+1;
		}
		if(exp[i] == ':'){
			std::string t;
			t.assign(exp, j, i-j);

			cs.pos = std::stoi(t);
			j = i+1;
			// Here we allocated cooedinates
			break;
		}
	}
	std::string tline;
	tline.assign(exp, j, exp.length()-2);
	// Checking type of content
	for(uint i=j; i<exp.length(); i++){
		if(exp[i]>'9' || exp[i]<'-' || exp[i] == '/'){
			// Content is string

			INode *r = new NodeStr(tline);
			r->setCoordinates(cs.lev, cs.pos);
			return r;
		}
	}

	for(uint i=j; i<exp.length(); i++){
		if(exp[i] == '.'){
			// Content is float
			float v = std::stof(tline);
			INode *r = new NodeFl(v);
			r->setCoordinates(cs.lev, cs.pos);
			return r;
		}
	}
	// Content is integer
	int v = std::stoi(tline);
	INode *r = new NodeInt(v);
	r->setCoordinates(cs.lev, cs.pos);
	return r;
}

int main(int argc, char **argv){
	if(argc < 2){
		std::cout << "Not enough arguments" << std::endl;
		std::cout << "Usage example is:" << std::endl;
		std::cout << "./bin \"filename.filetype\"" << std::endl;
		return -1;
	}
	std::ifstream inf(argv[1]);
	std::string line;
	if(inf.is_open()) {
		while ( std::getline (inf,line) ){
			std::cout << line << '\n';
		}
		inf.close();
	}
  else{
		std::cout << "Unable to open file" << std::endl;
		return -2;
	}

	// We should divide expression to the separate nodes
	std::vector<uint> obp, cbp; // obp- "open bracket position", cbp- "close bracket position"
	for(uint i=0; i<line.length(); i++){
		char c = line[i];
		if(c == '{') obp.push_back(i);
		if(c == '}') cbp.push_back(i);
	}

	if(obp.size() != cbp.size()){
		std::cout<<"Expression have uncoupled brackets"<<std::endl;
		return -3;
	}
	
	if(!obp.size() < 0) return -4;

	std::vector<INode*> nodes;
	
	for(uint i=0; i<obp.size(); i++){
			std::string tl;
			tl.assign(line, obp[i], cbp[i]-obp[i]);

			INode *p = allocator(tl);
			std::cout << "type=" << p->nodeType() << ", lev=" << p->getCoordinates().lev << ", pos=" << p->getCoordinates().pos << std::endl;
			std::cout << "\t" << "\"";
			switch(p->nodeType()){
				case INT:
					std::cout << *(int*)p->getContent();
					break;
				case FLOAT:
					std::cout << *(float*)p->getContent();
					break;
				case STR:	
					std::cout << *(std::string*)p->getContent();
					break;
				deafult:
					std::cout << "Undefined type" << std::endl;
					break;
			}
			std::cout <<"\"" << std::endl;
	}

	return 0;
}
