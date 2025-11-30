#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int par[1000];
int rankk[1000];
int findpar(int node){
    if (par[node] == node) return node;
    return par[node] = findpar(par[node]);
}
void unionSet(int u, int v){
    u = findpar(u);
    v = findpar(v);
    if (u == v) return; 
    if (rankk[u] < rankk[v]) par[u] = v;
    else if (rankk[u] > rankk[v]) par[v] = u;
    else{
        par[v] = u;
        rankk[u]++; 
    }
}
int main(){
    int n,m;
    cout<<"Enter num of nodes and edges: ";
    cin>>n>>m;
    vector<pair<int, pair<int, int>>> adj;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({w, {u, v}});
    }
    for (int i = 0; i < n; i++){
        par[i] = i;
        rankk[i] = 0;
    }
    sort(adj.begin(), adj.end());
    int wt = 0;
    vector<pair<int, pair<int, int>>> mst;
    for (auto &e : adj){
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (findpar(u) != findpar(v)){
            unionSet(u, v);
            mst.push_back(e);
            wt += w;
        }
    }
    for (auto &e : mst){
        cout << e.second.first << " - " << e.second.second<<"  "<< e.first << "\n";
    }
    return 0;
}
