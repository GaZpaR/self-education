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

	void push(contenttype val){
		node<contenttype> *tempnode = new node<contenttype>;
		tempnode->content = val;
		tempnode->linkprev = lastnode;
		tempnode->linknext = tempnode;
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

int main()
{
	linkedlist<int> somel(150);
	for(uint i=0; i<128; i++){
		somel.push(i*2);
		std::cout<<" "<<i*2<<" ";
	}
	somel.insert(0, 55);
	somel.insert(0, 166);
	somel.insert(3, 71);
	std::cout<<std::endl;
	somel.delelement(137);
	somel.delelement(124);
	somel.delelement(115);
	for(uint i=1; i<somel.listsize(); i++){
		std::cout<<" "<<somel[i]<<" ";
	}
	std::cout<<std::endl;

	std::cout<<"Bye bye!"<<std::endl;
	return 0;
}
