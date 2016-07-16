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

	link *heads;
	int N, M;

	T searchR(link& h, key v){
		if(h == 0) return heads;
		key t = h->item.key();
		if(v == t) return h->item();
		if(v<t)
			return searchR(h->l, v);
		else
			return searchR(h->r, v);
	}

	int hash(key v, int M){
		return v &(M-1);
	}
public:
	ST(int maxN){
		N = 0;
		M = maxN/5;
		heads = new link[M];
		for(int i=0; i<M; i++) heads[i] = 0;
	}

	T search(key v){
		return searchR(heads[hash(v, M)], v);
	}

	void insert(T i){
		int p = hash(i.key(), M);
		heads[p] = new node(i, heads[p]);
		N++;
	}
};

int main(int argc, char **argv)
{
	std::cout<<"Result of power is: "<<std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
