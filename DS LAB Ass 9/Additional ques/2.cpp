#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<climits>
using namespace std;
class graph {
public:
    unordered_map<int, list<pair<int,int>>> adj;
    void addedge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
    }
    void dij(int n, int src, int cost) {
        int dis[n];
        for (int i = 0; i < n; i++){
            dis[i] = INT_MAX;
        }
        set<pair<int,int>> s;
        dis[src] = cost;
        s.insert(make_pair(dis[src], src));
        while (!s.empty()) {
            auto t = *(s.begin());
            int d = t.first;
            int node = t.second;
            s.erase(s.begin());
            for (auto i : adj[node]) {
                if (d + i.second < dis[i.first]) {
                    auto f = s.find(make_pair(dis[i.first], i.first));
                    if (f != s.end()) s.erase(f);
                    dis[i.first] = d + i.second;
                    s.insert(make_pair(dis[i.first], i.first));
                }
            }
        }
        cout << dis[n - 1];
    }
};
int main() {
    graph g;
    int grid[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    int m = 3, n = 3;
    int tot = m * n;
    int A[4] = {-1, 1, 0, 0};
    int B[4] = {0, 0, -1, 1};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int u = i * n + j;
            for (int k = 0; k < 4; k++) {
                int a = i + A[k];
                int b = j + B[k];
                if (a >= 0 && a < m && b >= 0 && b < n) {
                    int v = a * n + b;
                    g.addedge(u, v, grid[a][b]);
                }
            }
        }
    }
    g.dij(tot, 0, grid[0][0]);
    return 0;
}
