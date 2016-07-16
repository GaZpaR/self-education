#include <iostream>
#define NULLdigit 0x00000001
const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1<<bitsbyte;

int msbAllocation(int i){
	// This part depends on "int" value= 31 bit;
	int mask = 0x40000000; // =0b0000000000000000000000000000001
	for(int m=0; m<31; m++){
		if((i&mask) == mask) break;
		mask >>= 1;
	}
	return mask;
};

template<class Item>
inline int digit(Item A, int B){
	return (A*((Item)1<<B) > 0)? 1: 0;
}

template<class T, class key>
class ST{
private:
	struct node{
		T item;
		int d;
		node *l, *m, *r;
		key bit;
		node(int k){
			d = k; l = 0; m = 0; r = 0;
		}
	};

	typedef node *link;
	link head;
	T nullItem;

	T searchR(link h, key v, int d){
		int i = digit(v, d);
		if(h == 0) return nullItem;
		if(i == NULLdigit){
			T dummy(v);
			return dummy;
		}

		if(i < h->d) return searchR(h->l, v, d);
		if(i == h->d) return searchR(h->m, v, d);
		if(i > h->d) return searchR(h->r, v, d);
	}

	void insertR(link& h, T x, int d){
		int i = digit(x.key(), d);
		if(i == 0) h = new node(i);
		if(i == NULLdigit) return;
		if(i < h->d) insertR(h->l, x, d);
		if(i == h->d) insertR(h->m, x, d);
		if(i > h->d) insertR(h->r, x, d);
	}

public:
	ST(int maxN){
		head = 0;
	};

	void insert(T x){
		insertR(head, x, 0);
	}

	T search(key v){
		return searchR(head, v, 0);
	}

};


int main(int argc, char **argv)
{

	std::cout<<"Bye bye!!!"<<std::endl;
	return 0;
}
