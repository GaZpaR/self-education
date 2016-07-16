#include <iostream>


template<class T, class key>
class ST{
private:
	T *st;
	int N, M;
	T nullitem;

	int hash(key v, int M){
		return v &(M-1);
	}

	void expand(){
		T *it = st;
		init(M+M);
		for(int i=0; i<M/2; i++)
			if(!it[i].null()) insert(it[i]);
		delete it;
	};

	void init(int n){
		N = 0;
		M = 2*n;
		st = new T[M];
		for(int i=0; i<M; i++) st[i] = nullitem;
	}
public:
	ST(int maxN){
		init(4);
	}

	T search(key v){
		int i = hash(v, M);
		while(!st[i].null()){
			if(v == st[i].key())
				return st[i];
			else i = (i+1)%M;

			return nullitem;
		}
	}

	void insert(T i){
		int p = hash(i.key(), M);
		while(!st[p].null()) p = (p+1)%M;
		st[p] = i;
		if(N++ >= M/2) expand();
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
