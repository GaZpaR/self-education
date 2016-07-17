#include <iostream>
#include <vector>

struct Edge{
	int v, w;
	Edge(int v = -1, int w = -1): v(v), w(w){

	};
};

class denseGRAPH{
private:
	// Code depending of realization
	int  Vcnt, Ecnt;
	bool digraph;
	std::vector<std::vector<bool>> adj;
public:
	denseGRAPH(int V, bool digraph = false):
	adj(V), Vcnt(V), Ecnt(0), digraph(digraph){
		for(int i=0; i<V; i++){
			adj[i].assign(V, false);
		}
	};
	~denseGRAPH(){};
	int V() const{return Vcnt;};
	int E() const{return Ecnt;};
	bool directed() const{return digraph;};
	int insert(Edge e){
		int v = e.v, w = e.w;
		if(adj[v][w] == false) Ecnt++;
		adj[v][w] = true;
		if(!digraph) adj[w][v] = true;
	};
	int remove(Edge e){
		int v = e.v, w = e.w;
		if(adj[v][w] == true) Ecnt--;
		adj[v][w] = false;
		if(!digraph) adj[w][v] = false;
	};
	bool edge(int v, int w){
		return adj[v][w];
	};
	class adjIterator{
		const denseGRAPH &G;
		int i, v;
	public:
		adjIterator(const denseGRAPH &, int v):
		G(G), v(v), i(-1){};
		int beg(){
			i = -1;
			return nxt();
		};
		int nxt(){
			for(i++; i<G.V(); i++){
				if(G.adj[v][i] == true) return i;
			}
			return -1;
		};
		bool end(){
			return i >= G.V();
		};
	};
	friend class adjIterator;
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
