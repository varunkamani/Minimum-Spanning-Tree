#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    char vertex1;
    char vertex2;
    int wieght;
    Edge(char a,char b,int c) : vertex1(a) , vertex2(b) , wieght(c){};
};
class Graph{
public:
    int n;
    vector<Edge> edges;
    vector<char> vertices;
    vector<int> id;
    vector<int> size;
    Graph(int n){
        this->n=n;
        vertices.resize(n);
        id.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            id[i]=i;
            size[i]=1;
        }
    }
    
};
int root(char a,Graph gh);
void Join(char a,char b,Graph &gh);
void Kruskal(Graph &gh);
int main(){
    Graph gh(6);
    for(int i=0;i<6;i++){
        gh.vertices.push_back(i+97);
    }
    gh.edges.push_back(Edge('a','b',4));
    gh.edges.push_back(Edge('a','f',2));
    gh.edges.push_back(Edge('f','b',5));
    gh.edges.push_back(Edge('c','b',6));
    gh.edges.push_back(Edge('c','f',1));
    gh.edges.push_back(Edge('f','e',4));
    gh.edges.push_back(Edge('d','e',2));
    gh.edges.push_back(Edge('d','c',3));
    Kruskal(gh);
    return 0;
}
int root(char a,Graph gh){
    int i=a;
    i=i-97;
    while(gh.id[i]!=i){
        i=gh.id[i];
    }
    return i;
}
void Join(char a,char b,Graph &gh){
    int i=a;
    int j=b;
    i=i-97;
    j=j-97;
    int roota=root(a,gh);
    int rootb=root(b,gh);
    if(gh.size[roota]>gh.size[rootb]){
        gh.id[rootb]=roota;
        gh.size[roota]+=gh.size[rootb];
    }
    else{
        gh.id[root(a,gh)]=j;
        gh.size[rootb]+=gh.size[roota];
    }
  
}
struct less_than_key
{
    inline bool operator() (const Edge& struct1, const Edge& struct2)
    {
        return (struct1.wieght < struct2.wieght);
    }
};
void Kruskal(Graph &gh){
    vector<Edge> A;
    std::sort(gh.edges.begin(),gh.edges.end(),less_than_key());
    vector<Edge>::iterator e;
    for(e=gh.edges.begin();e!=gh.edges.end();++e){
        if(root(e->vertex1,gh)!=root(e->vertex2,gh)){
            A.push_back(Edge(e->vertex1,e->vertex2,e->wieght));
            Join(e->vertex1,e->vertex2,gh);
        }
        }
        cout<<"All Graph edges and wieght : \n";
        for(e=gh.edges.begin();e!=gh.edges.end();++e){
        	cout<<e->vertex1<<" "<<e->vertex2<<"  "<<e->wieght<<"\n";
        }
        
    cout<<"\n Spanning Tree Edges  \n";
    for(e=A.begin();e!=A.end();++e){
            cout<<e->vertex1<<" "<<e->vertex2<<"  "<<e->wieght<<"\n";
        }
     }
