#include <iostream>
#include <vector>
#include <queue>

struct Edge{
    int v, w;
    Edge(int ve = -1, int we = -1): v(ve), w(we){
       v = ve;
       w = we;
    };
};

class denseGRAPH{
private:
// Code depending of implementation
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
        adj[w][v] = true;
        //if(digraph) adj[w][v] = true;
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
    adjIterator(const denseGRAPH &GR, int ve):
    G(GR), v(ve), i(0){};
    
    int beg(){
        return G.adj[v][0];
    };
    int nxt(){
        i++;
        if(i<G.V()) return G.adj[v][i];
        else return -1;
    };
    bool end(){
        return (i > (G.V() - 1));
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
    IO(){};
    ~IO(){};
    static void show(const Graph &);
    static void scanEZ(Graph &);
    static void scan(Graph &);
};

template<class Graph>
void IO<Graph>::show(const Graph &G){
    std::cout<<"   ";
    for(int s=0; s<G.V(); s++){
        std::cout.width(2);
        std::cout<<s<<":";
    }
    std::cout<<std::endl;
    for(int s=0; s<G.V(); s++){
        std::cout.width(2);
        std::cout<<s<<":";
        typename Graph::adjIterator A(G, s);
        for(int t = A.beg(); !A.end(); t=A.nxt()){
            std::cout.width(2);
            std::cout<< t << " ";
        }
        std::cout<<":"<<s;
        std::cout<<std::endl;
    }
    std::cout<<"   ";
    for(int s=0; s<G.V(); s++){
        std::cout.width(2);
        std::cout<<s<<":";
    }
    std::cout<<std::endl;
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

template <class Graph>
class cDFS{
    int cnt;
    const Graph &G;
    std::vector<int> ord;
    void searchC(int v){
        ord[v] = cnt++;
        typename Graph::adjIterator A(G, v);
        for(uint t = A.beg(), i=0; !A.end(); t = A.nxt(), i++){
            if(ord[i] == -1 && t == true){
                searchC(i);
                //std::cout << v << "->" << i << std::endl;
            }
        }
    }
public:
    cDFS(const Graph &g, int v = 0): G(g), cnt(0), ord(G.V(), -1){
        searchC(v);
    };
    int count() const {return cnt;}
    int operator[](int v) const {return ord[v];}
};

template <class Graph>
class cBFS{
    int cnt;
    const Graph &G;
    std::vector<int> ord;
    std::vector<int> st;
    void searchC(Edge e){
        std::queue<Edge> q;
        q.push(e);
        while(!q.empty()){
            Edge a = q.front();
            q.pop();
            std::cout << "a.v = " << a.v << ", a.w = " << a.w << std::endl;
            if(ord[a.w] == -1){
                int v = a.v, w = a.w, tovisit = -1;
                bool visit = true;
                ord[w] = cnt++;
                st[w] = v;
                typename Graph::adjIterator A(G, v);
                for(uint t = A.beg(), i=0; !A.end(); t = A.nxt(), i++){
                    if(ord[i] == -1 && t == true){
                        if(visit){
                            visit = false;
                            tovisit = i;
                        }
                        q.push(Edge(w, i));
                        std::cout << w << "->" << i << std::endl;
                    }
                }
                if(tovisit >= 0)
                    searchC(Edge(w, tovisit));
            }
        }
    }
    void search(void){
/*        for(uint j=0; j < (uint)G.V(); j++){
            typename Graph::adjIterator A(G, j);
            for(uint t = A.beg(), i=0; !A.end(); t = A.nxt(), i++){
                if(t == true){
                    searchC(Edge(j, i));
                    std::cout << j << "->" << i << std::endl;
                }
            }
        }
*/   
        searchC(Edge(0,0));
    }
public:
    cBFS(Graph &g): G(g), cnt(0), st(g.V(), -1), ord(g.V(), -1)
    {
        search();
    }
    uint count() const {return cnt;}
    int ST(int v) const{
        return st[v];
    }
    int operator[](int v) const {return ord[v];}
};
#define number(x) x
#define idx(x) e##x
int main()
{
    std::cout<< "Example of usage GRAPH, CC and other abstract classes" <<std::endl;
    denseGRAPH gr(9);
    Edge e1(0, 1), e2(0, 2), e3(1, 2), e4(1, 3), e5(3, 6), e6(2, 6), e7(2, 4),
         e8(4, 5), e9(5, 6), e10(5, 7), e11(6, 7), e12(4, 8), e13(8, 7), e14(2, 3);

    gr.insert(e1);
    gr.insert(e2);
    gr.insert(e3);
    gr.insert(e4);
    gr.insert(e5);
    gr.insert(e6);
    gr.insert(e7);
    gr.insert(e8);
    gr.insert(e9);
    gr.insert(e10);
    gr.insert(e11);
    gr.insert(e12);
    gr.insert(e13);
    gr.insert(e14);

    std::cout << "gr.V()= " << gr.V() << std::endl;
    IO<denseGRAPH> simio;
    simio.show(gr);
    cDFS<denseGRAPH> uf(gr);
    for(uint i=0; i < (uint)uf.count(); i++){
        std::cout << uf[i];
        if(i < (uint)uf.count()-1) std::cout << "->";
    }
    std::cout<< std::endl;

    cBFS<denseGRAPH> us(gr);
    for(uint i=0; i < us.count(); i++){
        //std::cout << us.ST(i);
        //if(i < (uint)uf.count()-1) std::cout << "->";
        std::cout << us[i];
        if(i < (uint)uf.count()-1) std::cout << "->";
    }

    std::cout<< std::endl;
    std::cout<< "Bye bye!" <<std::endl;
    return 0;
}
