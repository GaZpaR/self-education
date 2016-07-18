#include <iostream>
#include <vector>

struct Edge{
	int v, w;
	Edge(int v = -1, int w = -1): v(v), w(w){

	};
};

class SparseMultiGRAPH{
private:
	// Code depending of realization
	int  Vcnt, Ecnt;
	bool digraph;
	struct node{
		int v;
		node *next;
		node(int x, node *t):v(x), next(t){};
	};
	typedef node* link;
	std::vector<link> adj;
public:

	SparseMultiGRAPH(int V, bool digraph = false):
	adj(V), Vcnt(V), Ecnt(0), digraph(digraph){
			adj.assign(V, 0);
	};

	~SparseMultiGRAPH(){};
	int V() const{return Vcnt;};
	int E() const{return Ecnt;};
	bool directed() const{return digraph;};
	int insert(Edge e){
		int v = e.v, w = e.w;
		adj[v] = new node(w, adj[v]);
		if(!digraph) adj[w] = new node(v, adj[w]);
		Ecnt++;
	};
	int remove(Edge e);
	bool edge(int v, int w)const;
	class adjIterator;
	friend class adjIterator;
};

class SparseMultiGRAPH::adjIterator{
	const SparseMultiGRAPH &G;
	int v;
	link t;
public:
	adjIterator(const SparseMultiGRAPH &G, int v):
	G(G), v(v) {t = 0;};

	int beg(){
		t = G.adj[v];
		return t? t->v : -1;
	};

	int nxt(){
		if(t) t = t->next;
		return t? t->v : -1;
	};

	bool end(){
		return t == 0;
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

template<class Graph>
class CC{
private:
	//
public:
	CC(const Graph &);
	int count();
	bool connect(int, int);
};

int main()
{
	std::cout<< "Example of usage GRAPH, CC and other abstract classes" <<std::endl;


	std::cout<< "Bye bye!" <<std::endl;
	return 0;
}
