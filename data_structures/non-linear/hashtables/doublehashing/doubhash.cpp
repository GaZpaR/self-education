#include <iostream>


template<class T, class key>
class ST{
private:
	T *st;
	int N, M;
	T nullitem;

	inline int hash(key v, int M){
		return v &(M-1);
	}

	inline int hashtwo(key v, int M){
		return (v%M)+1;
	}
public:
	ST(int maxN){
		N = 0;
		M = 2*maxN;
		st = new T[M];
		for(int i=0; i<M; i++) st[i] = 0;
	}

	T search(key v){
		int i = hash(v, M), k = hashtwo(v, M);
		while(!st[i].null()){
			if(v == st[i].key())
				return st[i];
			else i = (i+k)%M;

			return nullitem;
		}
	}

	void insert(T i){
		key v = i.key();
		int p = hash(i.key(), M), k = hashtwo(v, M);
		while(!st[p].null()) p = (p+k)%M;
		st[p] = i;
		N++;
	}

	void remove(T x){
		int i = hash(x.key(), M), j;
		while(!st[i].null())
			if(x.key() == st[i].key())
				break;
			else
				i = (i+1)%M;
		if(st[i].null()) return;
		st[i] = nullitem; N--;
		for(j=i+1; !st[j].null(); j=(j+1)%M, N--){
			T v = st[j];
			st[j] = nullitem;
			insert(v);
		}
	}
};

int main(int argc, char **argv)
{

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
