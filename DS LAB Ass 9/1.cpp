#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class graph {
public:
    unordered_map<int, list<int>> adjlist;
    void addedge(int u, int v, bool direction) {
        adjlist[u].push_back(v);
        if (direction == 0)  adjlist[v].push_back(u);
    }
    void bfs(int d,unordered_map<int, bool> vis) {
        queue<int> q;
        q.push(d);
        vis[d] = true;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            cout << f << " ";
            for (auto i : adjlist[f]) {
                if (!vis[i]) {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
};
int main() {
    graph g;
    int n, m;
    cout<<"Enter num of nodes and edges: ";
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0);
    }
    unordered_map<int, bool> vis;
    int d;
    cout<<"Enter node to start: ";
    cin >> d;
    cout << "BFS: ";
    g.bfs(d,vis);
}
