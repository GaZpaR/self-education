#include "deserializer.hpp"

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
			// Here we allocated coordinates
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
			r->setContent(tline);
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

Tree deserializeTree(std::string ifilename){
	std::cout << "DESERIALIZER" << std::endl;
	if(ifilename.length() == 0){
		std::cout << "File name which content is serialized tree is equal 0" << std::endl;
		return (Tree)NULL;
	}
	std::ifstream inf(ifilename);
	std::string line;
	if(inf.is_open()) {
		while ( std::getline (inf,line) ){
			std::cout << line << '\n';
		}
		inf.close();
	}
  else{
		std::cout << "Unable to open file" << std::endl;
		return (Tree)NULL;
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
		return (Tree)NULL;
	}
	
	if(!obp.size() < 0) return (Tree)NULL;

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
			nodes.push_back(p);
	}
	
	std::cout << "list of unordered nodes/>" << std::endl;
	// nodes[0] is root of reconstructing tree
	static Tree t(nodes[0]);

	for(uint i=1, j=1; i<nodes.size(); i++){
		INode *p = nodes[i];
		uint l = p->getCoordinates().lev, pos = p->getCoordinates().pos;
		
		if(l == 1){
			t.appendNode(nodes[i]);
			j = l;
			continue;
		}

		if(l == j){
			if(pos>1)t.appendNode(nodes[i-1]->getParent(), p);
			else t.appendNode(nodes[i-1], p);
			j = l;
			continue;
		}

		if(l > j){
			t.appendNode(nodes[i-1], p);
			j = l;
			continue;
		}
		else{
			t.appendNode( nodes[i-1]->getParent()->getParent(), p);
			j = l;
		}
	}
	
	// Traverse of tree from "input" file
	std::vector<std::string> out;
	t.traverseTree(t.getRoot(),// Lambda expression begins
		[](INode *n, std::vector<std::string> &o) {
			NC cs = n->getCoordinates();

			std::cout << "level=" << cs.lev << ", position=" << cs.pos << ": ";
			std::string fe('{' + std::to_string(cs.lev) + '.' + std::to_string(cs.pos)+ ':');

			switch(n->nodeType()){
				case INT:
					fe += std::to_string(*(int*)n->getContent());
					std::cout <<  *(int*)n->getContent() << std::endl;
					break;
				case FLOAT:
					fe += std::to_string(*(float*)n->getContent());
					std::cout << *(float*)n->getContent() << std::endl;
					break;
				case STR:
					fe += (*(std::string*)n->getContent());
					std::cout << *(std::string*)n->getContent() << std::endl; 
					break;
				default: std::cout << "Undefined Node content type" << std::endl; break;
			}
			fe += "}";
			o.push_back(fe);
		}// end of lambda expression
	, out);
	
	return t;
}
