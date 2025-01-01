#include <iostream>
# include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u , int v , bool direction){
        //direction=0->Undirected graph
        //diretion=1 -? directed graph
        
        //create an edge from u to v
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j :i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main() {
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    
    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating an undiredted graph
        g.addEdge(u,v,0);
        
    }
    g.printAdjList();
}

Output:
Enter the number of nodes
5
Enter the number of edges
6
0 1 
1 2 
2 3 
3 1 
3 4 
0 4 
4->3, 0, 
3->2, 1, 4, 
2->1, 3, 
1->0, 2, 3, 
0->1, 4, 

