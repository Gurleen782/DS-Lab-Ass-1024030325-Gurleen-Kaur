#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<climits>
using namespace std;
class graph{
    public:
    unordered_map<int,list<pair<int,int>>>adj;
    void addedge(int u,int v,int w,bool direction){
        adj[u].push_back(make_pair(v,w));
        if(direction==0) adj[v].push_back(make_pair(u,w));
    }
    void prims(int n){
        int key[n];
        bool mst[n];
        int par[n];
        for(int i=0;i<n;i++){
            key[i]=INT_MAX;
            mst[i]=false;
            par[i]=-1;
        }
        key[0]=0;
        for(int i=0;i<n;i++){
            int min=INT_MAX;
            int u;
            for(int v=0;v<n;v++){
                if(mst[v]==false && key[v]<min){
                    min=key[v];
                    u=v;
                }
            }
            mst[u]=true;
            for(auto i:adj[u]){
                int node=i.first;
                int w=i.second;
                if(mst[node]==false && w<key[node]){
                    key[node]=w;
                    par[node]=u;
                } 
            }
        }
        for(int i=1;i<n;i++){
            cout<<par[i]<<"->"<<i<<"  "<<key[i]<<endl;
        }
        for(int i=0;i<n;i++){
            cout<<key[i]<<" ";
        }
    }
};
int main(){
    graph g;
    int n,m;
    cout<<"Enter num of nodes and edges: ";
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u,v,w,0);
    }
    g.prims(n);
}
