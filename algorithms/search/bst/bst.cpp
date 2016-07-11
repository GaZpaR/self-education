#include <iostream>


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

	void insertR(link& h, T x){
		if(h == 0){
			h = new node(x);
			return;
		}
		if(x.key() < h->item.key())
			insertR(h->l, x);
		else
			insertR(h->r, x);
	}

	void showR(link h, std::ostream& os){
		if(h == 0) return;

		showR(h->l, os);
		h->item.show(os);
		showR(h->r, os);
	}
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
	if(a ==(int)NULL) a = 0;

	std::cout<<"Result of power is: "<<std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
