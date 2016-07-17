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

int main()
{

	std::cout<< "Bye bye!" <<std::endl;
	return 0;
}
