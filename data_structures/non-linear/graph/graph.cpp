#include <iostream>
#include <vector>

struct Edge{
	int v, w;
	Edge(int v = -1, int w = -1): v(v), w(w){

	};
};

class GRAPH{
private:
	// Code depending of realization
public:
	GRAPH(int, bool);
	~GRAPH();
	int V() const;
	int E() const;
	bool directed() const;
	int insert(Edge);
	int remove(Edge);
	bool edge(int, int);
	class adjIterator{
		adjIterator(const GRAPH &, int);
		int beg();
		int nxt();
		bool end();
	};
};

template<class Graph>
std::vector<Edge> edges(Graph &G){
	int E = 0;
	std::vector<Edge> a(G.E());
	for(int v=0; v<G.V(); v++){
		typename Graph::adjIterator A(G, v);
		for(int w = A.beg(); !A.end(); w = A.nxt())
			if(G.directed() || v<w)
				a[E++] = Edge(v, w);
	}
	return a;
}
template<class Graph>
class IO{
public:
	static void show(const Graph &);
	static void scanEZ(Graph &);
	static void scan(Graph &);
};

template<class Graph>
void IO<Graph>::show(const Graph &G){
	for(int s=0; s<G.V(); s++){
		std::cout.width(2);
		std::cout<<s<<":";
		typename Graph::adjIterator A(G, s);
		for(int t = A.beg(); !A.end(); t=A.nxt()){
			std::cout.width(2);
			std::cout<< t << " ";
		}
		std::cout<<std::endl;
	}
}

int main()
{

	std::cout<< "Bye bye!" <<std::endl;
	return 0;
}
