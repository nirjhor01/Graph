#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    std::vector<vector<pair<int,int>>> v(n);
    for(int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        v[x].push_back({y, w});
    }

    int st = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   less<pair<int, int>>>	q;
    q.push({0, st});

    vector<bool>visited(n, 0);
    vector<int>dis(n, 1e5);
    dis[0] = 0;
    visited[0] = 1;
    while(!q.empty()) {
        int f = q.top().second;
        q.pop();
        //if(visited[f]) continue;
        visited[f] = 1;
        for(auto [u, w]: v[f]) {
            if(dis[f] + w < dis[u]) dis[u] = dis[f] + w;
                q.push({-dis[u], u});
        }


    }

    for(auto i: dis) {
        cout << i << ' ';
    }
    cout << '\n';

}
/*
5 6
1 2 10
1 3 2
1 4 2
1 5 13
4 5 10
2 5 1
*/
