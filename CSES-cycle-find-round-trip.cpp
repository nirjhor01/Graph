#include<bits/stdc++.h>
using namespace std;
std::vector<vector<int>> v;
std::vector<int> vis;
vector<int>par;
int st_node, end_mode;
int dfs(int node, int p) {
    vis[node] = 1;
    par[node] = p;
    for(auto nd: v[node]) {
        if(nd == p) continue;
        if(vis[nd] == 1) {
            st_node = nd;
            end_mode = node;
            return 1;
        }
        if(vis[nd] == 0) {
            if(dfs(nd, node) == 1) return 1;
        }
    }
    return 0;
}
int main() {
    int n;
    int m;
    cin >> n >> m;
    v.resize(n + 1);
    vis.resize(n + 1, 0);
    par.resize(n + 1);
    while(m--) {
        int x;
        int y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int ok = 0;
    for(int i = 1; i <= n; ++i) {
        if(vis[i] == 0) {
            if(dfs(i, -1) == 1) {
                ok = 1;
                break;
            }
        }
    }
    if(ok == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int tv = end_mode;
    vector<int>ans;
    ans.push_back(tv);
    while(tv != st_node) {
        ans.push_back(par[tv]);
        tv = par[tv];
    }
    cout << ans.size() << '\n';
    for(auto i: ans) {
        cout << i << ' ';
    }
    cout << '\n';

}
