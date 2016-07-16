#include <iostream>

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
		node *l, *r;
		key bit;
		node(T x){
			item = x; l = 0; r = 0;
		}
	};

	typedef node *link;
	link head;
	T nullItem;

	T searchR(link h, key v, int d){
		if(h->bit <= d) return h->item;
		if(digit(v, h->bit) == 0)
			return searchR(h->l, v, h->bit);
		else
			return searchR(h->r, v, h->bit);
	}

	link insertR(link& h, T x, int d, link& p){
		key v = x.key();
		if((h->bit >= d) || (h->bit <= p->bit)){
			link t = new node(x);
			t->bit = msbAllocation(x);
			t->l = (digit(v, t->bit))? h : t;
			t->r = (digit(v, t->bit))? t : h;
		}
		if(digit(v, h->bit) == 0)
			h->l = insertR(h->l, x, d, h);
		else
			h->r = insertR(h->r, x, d, h);
		return h;
	}

	void showR(link h, std::ostream& os){
		if(h == 0) return;

		showR(h->l, os);
		h->item.show(os);
		showR(h->r, os);
	}

	link split(link p, link q, int d){
		link t = new node(nullItem);
		t->N = 2;
		key v = p->item.key();
		key w = q->item.key();
		switch(digit(v, d)*2 + digit(w, d)){
			case 0: t->l = split(p, q, d+1); break;
			case 1: t->l = p; t->r = q; break;
			case 2: t->r = p; t->l = q; break;
			case 3: t->r = split(p, q, d+1); break;
		}
		return t;
	}
public:
	ST(int maxN){
		head = new node(nullItem);
		head->l = head->r = head;
	};

	void insert(T x){
		int i;
		key v = x.key();
		key w = searchR(head->l, v, -1).key();
		if(v == w) return;
		for(i=0; digit(v, i) == digit(w, i); i++);
		head->l = insertR(head->l, x, i, head);
	}

	T search(key v){
		T t = searchR(head, v, -1);
		return (v == t.key())? t : nullItem;
	}

	void show(std::ostream& os){
		showR(head, os);
	}
};


int main(int argc, char **argv)
{

	std::cout<<"Bye bye!!!"<<std::endl;
	return 0;
}
