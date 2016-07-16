#include <iostream>

const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1<<bitsbyte;

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
		node(T x){
			item = x; l = 0; r = 0;
		}
	};

	typedef node *link;
	link head;
	T nullItem;

	T searchR(link h, key v, int d){
		if(h == 0) return nullItem;
		if(h->l == 0 && h->r == 0){
			key w = h->item.key();
			return (v == w)? h->item : nullItem;
		}

		if(digit(v, d) == 0)
			return searchR(h->l, v, d+1);
		else
			return searchR(h->r, v, d+1);
	}

	void insertR(link& h, T x, int d){
		if(h == 0){
			h = new node(x);
			return;
		}
		if(h->r == 0 && h->l == 0){
			h = split(new node(x), h, d);
			return;
		}
		if(digit(x.key(), d) == 0)
			insertR(h->l, x, d+1);
		else
			insertR(h->r, x, d+1);
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
		head = 0;
	};

	void insert(T x){
		insertR(head, x, 0);
	}

	T search(key v){
		return searchR(head, v, 0);
	}

	void show(std::ostream& os){
		showR(head, os);
	}
};


int main(int argc, char **argv)
{
	int
	a = atoi(argv[1]),
	pw = atoi(argv[2]);
	std::cout<<a<<std::endl;
	std::cout<<pw<<std::endl;
	if(pw == (int)NULL) pw = 0;
	if(a ==(int)NULL) a = 0;

	std::cout<<"Result of power is: "<<std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
