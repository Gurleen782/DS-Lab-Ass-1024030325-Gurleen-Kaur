#include<unordered_map>
#include<list>
#include<vector>
#include<iostream>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>adjlist;
    void addedge(int u,int v,bool direction){
        adjlist[u].push_back(v);
        if(direction==0) adjlist[v].push_back(u);
    }
    void dfs(int d,unordered_map<int,bool>vis){
        vis[d]=1;
        cout<<d<<" ";
        for(auto i:adjlist[d]){
            if(!vis[i]) dfs(i,vis);
        }
    }
};
int main(){
    int n,m;
    cout<<"Enter num of nodes and edges: ";
    cin>>n>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,0);
    }
    int d;
    cout<<"Enter node to start:";
    cin>>d;
    unordered_map<int,bool>vis;
    g.dfs(d,vis);
}
