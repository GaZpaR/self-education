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
public:
	ST(int maxN){
		head = 0;
	};

	void insert(T x){
		insertR(head, x);
	}

	T search(key v){
		return searchR(head, v);
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
	if(a == (int)NULL) a = 0;

	//std::cout<<"Result of power is: "<<power<int>(a, pw)<<std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
