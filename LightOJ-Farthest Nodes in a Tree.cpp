#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
void dfs(int node, int d, int &mx, int dis[], bool vis[],vector<pair<int,int>>adj[]) {
    if(vis[node] == 1) return;
    vis[node]= 1;
    mx = max(mx, d);
    dis[node] = d;
    for(auto[u, w]: adj[node]) {
        dfs(u, d + w, mx, dis, vis, adj);
    }
    return;
}
int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        int n, mx = 0;
        cin >> n;
        int dis[n];
        bool vis[n];
        std::vector<pair<int,int>> adj[n];
        for(int i = 0; i < n; i++) {
            vis[i] = 0;
            dis[i] = 0;
        }
        int x, y, w;

        for(int i = 0; i < n - 1; i++) {
            cin >> x >> y >> w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        dfs(0, 0, mx, dis, vis, adj);
        int next_node;
        for(int i = 0; i < n; ++i) {
            if(dis[i] == mx) {
                next_node = i;
                break;
            }
        }

        for(int i = 0; i < n; ++i) vis[i] = 0;
        mx = 0;
        dfs(next_node, 0, mx, dis, vis, adj);
        cout << "Case " << i << ": " << mx << '\n';

    }
}
