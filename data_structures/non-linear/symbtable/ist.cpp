#include <iostream>

#define MAX (1024*1024)

template<class T>
class Item{
private:
	T keyval;
	float info;
public:
	Item(){
		keyval = MAX;
	}
	Item(int maxKey){
		keyval = maxKey;
	}

	T key(){
		return keyval;
	}

	int null(){
		return keyval == MAX;
	}

	void rand(){
		keyval = 1000*::rand()/RAND_MAX;
		info = 1.0*::rand()/RAND_MAX;
	}
	void show(std::ostream &os = std::cout){
		os <<keyval<<" "<<info<<std::endl;
	}
};

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

	T searchR(link h, key v){
		if(h == 0) return nullItem;
		key t = h->item.key();
		if(v == t) return h->item();
		if(v<t)
			return searchR(h->l, v);
		else
			return searchR(h->r, v);
	}

	void insertT(link& h, T x){
		if(h == 0){
			h = new node(x);
			return;
		}
		if(x.key() < h->item.key()){
			insertR(h->l, x);
			rotRight(h);
		}
		else{
			insertR(h->r, x);
			rotLeft(h);
		}
	}

	void showR(link h, std::ostream& os){
		if(h == 0) return;

		showR(h->l, os);
		h->item.show(os);
		showR(h->r, os);
	}

	void rotRight(link& h){
		link x = h->l;
		h->l = x->r;
		x->r = h;
		h = x;
	};
	void rotLeft(link& h){
		link x = h->r;
		h->r = x->l;
		x->l = h;
		h = x;
	};

	T selectR(link h, int k){
		if(h == 0) return nullItem;
		int t =(h->l == 0)? 0: h->l->N;
		if(t>k) return selectR(h->l, k);
		if(t<k) return selectR(h->r, k-t-1);
		return h->item;
	};

	link joinLR(link a, link b){
		if(b == 0) return a;
		partR(b, 0);
		b->l = a;
		return b;
	}

	void removeR(link& h, key v){
		if(h == 0) return;
		key w = h->item.key();
		if(v<w) removeR(h->l, v);
		if(w<v) removeR(h->r, v);
		if(v == w){
			link t = h;
			h = joinLR(h->l, h->r);
			delete t;
		}
	}

	link joinR(link a, link b){
		if(b == 0) return a;
		if(a == 0) return b;
		insertT(b, a->item);
		b->l = joinR(a->l, b->l);
		b->r = joinR(a->r, b->r);
		delete a;
		return b;
	}
public:
	ST(int maxN){
		head = 0;
	};

	void insert(T x){
		insertR(head, x);
	}

	void remove(T x){
		removeR(head, x.key());
	}

	T search(key v){
		return searchR(head, v);
	}

	void show(std::ostream& os){
		showR(head, os);
	}

	T select(int k){
		return selectR(head, k);
	}

	void partR(link& h, int k){
		int t = (h->l == 0)? 0:h->l->N;
		if(t>k){
			partR(h->l, k);
			rotRight(h);
		}
		if(t<k){
			partR(h->r, k-t-1);
			rotLeft(h);
		}
	}

	void join(ST<T, key>& b){
		head = joinR(head, b.head);
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
	if(a == (int)NULL) a = 0;

	//std::cout<<"Result of power is: "<<power<int>(a, pw)<<std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
