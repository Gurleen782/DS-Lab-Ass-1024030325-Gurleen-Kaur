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
    void dij(int n,int src){
        int dis[n];
        for(int i=0;i<n;i++){
            dis[i]=INT_MAX;
        }
        set<pair<int,int>>s;
        dis[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto t=*(s.begin());
            int d=t.first;
            int node=t.second;
            s.erase(s.begin());
            for(auto i:adj[node]){
                if(d+i.second < dis[i.first]){
                    auto f=s.find(make_pair(dis[i.first],i.first));
                    if(f != s.end()) s.erase(f);
                    dis[i.first]=d+i.second;
                    s.insert(make_pair(dis[i.first],i.first));
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<dis[i]<<" ";
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
    int src;
    cout<<"enter src:";
    cin>>src;
    g.dij(n,src);
}
