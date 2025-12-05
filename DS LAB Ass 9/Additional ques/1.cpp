#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
    unordered_map <int, list<int>> adj;
    void addedge (int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs (int d, unordered_map<int, bool> &vis) {
        vis[d] = true;
        for (auto i : adj[d]) {
            if (!vis[i]) dfs (i, vis);
        }
    }
};
int main () {
    graph g;
    int n, m;
    cout << "Enter num of vertices and edges: ";
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addedge (u, v);
    }
    unordered_map<int, bool> vis;
    int comp = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]) {
            comp++;
            g.dfs (i, vis);
        }
    }
    cout << "Num of comp: " << comp;
}
