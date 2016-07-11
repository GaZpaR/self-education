#include <iostream>


template<class T, class key>
class ST{
private:
	T nullItem, *st;
	int N;
public:
	ST(int maxN){
		st = new T[maxN + 1];
		N=0;
	};

	int count(){
		return N;
	};

	void insert(T x){
		int i = N++;
		key v = x.key();
		while(i>0 && v<st[i-1].key()){
			st[i] = st[i-1];
			i--;
		}
		st[i] = x;
	}

	T search(int l, int r, key v){
		if(l >= r) return nullItem;
		int m = (l+r)/2;
		if(v == st[m].key()) return st[m];
		if(v < st[m].key())
			return search(l, m-1, v);
		else
			return search(m+1, r, v);
	}

	T select(int k){
		return st[k];
	};
	void show(std::ostream &os){
		int i=0;
		while(i<N) st[i++].show(os);
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
