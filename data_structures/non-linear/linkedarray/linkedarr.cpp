#include <iostream>

template<typename contenttype>
struct node{
	node *linkprev, *linknext;
	contenttype content;
};

template<typename contenttype>
class linkedlist{
private:
	node<contenttype> *firstnode, *lastnode;
	uint nodescounter;

public:
	linkedlist(){
		firstnode = new node<contenttype>;
		nodescounter = 1;
		firstnode->linkprev = firstnode;
		firstnode->linknext = firstnode;
		firstnode->content = NULL;
		lastnode = firstnode;
	};
	linkedlist(contenttype initval){
		firstnode = new node<contenttype>;
		nodescounter = 1;
		firstnode->linkprev = firstnode;
		firstnode->linknext = firstnode;
		firstnode->content = initval;
		lastnode = firstnode;
	};

	~linkedlist(){
		node<contenttype> *pos = firstnode;
		while(pos != lastnode){
			pos = pos->linknext;
			delete pos->linkprev;
		}
	};

	contenttype operator[](uint position){
		if(position >= nodescounter && position <= 0){
			std::cout<<"This element doesn't exist"<<std::endl;
			return (contenttype)NULL;
		}
		else{
			uint cnt = position;
			node<contenttype> *pos = firstnode;
			while(cnt--){
				pos = pos->linknext;
			}
			return pos->content;
		}
	}

	contenttype getelement(uint position){
		if(position >= nodescounter && position <= 0){
			std::cout<<"This element doesn't exist"<<std::endl;
			return (contenttype)NULL;
		}
		else{
			uint cnt = position;
			node<contenttype> *pos = firstnode;
			while(cnt--){
				pos = pos->linknext;
			}
			return pos->content;
		}
	}

	void push(contenttype val){
		node<contenttype> *tempnode = new node<contenttype>;
		tempnode->content = val;
		tempnode->linkprev = lastnode;
		tempnode->linknext = lastnode;
		lastnode->linknext = tempnode;
		lastnode = tempnode;
		nodescounter++;
	};

	void insert(uint position, contenttype val){
		if(position <= nodescounter && position >= 0){
			node<contenttype> *tempnode = new node<contenttype>;
			tempnode->content = val;
			uint cnt = position;
			node<contenttype> *pos = firstnode;
			while(cnt--){
				pos = pos->linknext;
			}
			pos->linknext->linkprev = tempnode;
			node<contenttype> *tmp = pos->linknext;
			pos->linknext = tempnode;
			tempnode->linkprev = pos;
			tempnode->linknext = tmp;
			nodescounter++;
		}
		else std::cout<<"There is no such place where we could insert this element"
			<<std::endl;
	};

	contenttype cutelement(uint position){
		contenttype retval = (contenttype)NULL;
		if(position <= nodescounter && position >= 0){
			uint cnt = position;
			node<contenttype> *pos = firstnode, *prev, *next;
			while(cnt--){
				pos = pos->linknext;
			}
			retval = pos->content;
			prev = pos->linkprev;
			next = pos->linknext;
			delete pos;
			prev->linknext = next;
			next->linkprev = prev;
			nodescounter--;
		}
		else std::cout<<"We can't cut this elementbecause this element doesn't exist"
				<<std::endl;
		return retval;
	};

	void delelement(uint position){
		if(position <= nodescounter && position >= 0){
			uint cnt = position;
			node<contenttype> *pos = firstnode, *prev, *next;
			while(cnt--){
				pos = pos->linknext;
			}
			prev = pos->linkprev;
			next = pos->linknext;
			delete pos;
			prev->linknext = next;
			next->linkprev = prev;
			nodescounter--;
		}
		else std::cout<<"We can't delete this element because this element doesn't exist"
				<<std::endl;
	};

	uint listsize()
	{
		return nodescounter;
	};

};

template<typename contenttype>
class linkedarray{
private:
	uint xsize, ysize;
	linkedlist<contenttype> *arrptr;
public:
	linkedarray(uint x, uint y){
		xsize = x;
		ysize = y;
		arrptr = new linkedlist<contenttype>[xsize];
		for(uint i=0; i<xsize; i++){
			for(uint j=0; j<ysize; j++){
				arrptr[i].push(0);
			}
		}
	};
	~linkedarray(){
		delete arrptr;
	};

	contenttype getelement(uint xpos, uint ypos){
		if(xpos >= xsize || xpos < 0){
			std::cout<<"This element doesn't exist: xsize"<<std::endl;
			return (contenttype)NULL;
		}
		else{
			if(ypos >= ysize || ypos < 0){
				std::cout<<"This element doesn't exist: ysize"<<std::endl;
				return (contenttype)NULL;
			}
			else{
				return arrptr[xpos].getelement(ypos);
			}
		}
	};
	void setelement(uint xpos, uint ypos, contenttype val){
		if(xpos >= xsize || xpos < 0){
			std::cout<<"Can't set this value: xsize"<<std::endl;
		}
		else{
			if(ypos >= ysize || ypos <0){
				std::cout<<"Can't set this value: ysize"<<std::endl;
			}
			else{
				arrptr[xpos].delelement(ypos);
				if(ypos>0)	arrptr[xpos].insert(ypos - 1, val);
				else arrptr[xpos].insert(0, val);

			}
		}
	};
};

int main()
{
	uint x = 5, y = 10;
	std::cout<<"Hello"<<std::endl;
	{
		linkedarray<uint> somear(x,y);
		for(uint i=0; i<x; i++){
			for(uint j=0; j<y; j++){
				somear.setelement(i, j, i+j);
				std::cout<<"content("<<i<<","<<j<<")="<<i+j<<"; ";
			}
		}
		std::cout<<std::endl;

		std::cout<<"Check content"<<std::endl;

		for(uint i=0; i<x; i++){
			for(uint j=0; j<y; j++){
				std::cout<<"content("<<i<<","<<j<<")="<<somear.getelement(i, j)<<"; ";
			}
		}
		std::cout<<std::endl;
	}
	
	std::cout<<"Bye bye!"<<std::endl;
	return 0;
}
