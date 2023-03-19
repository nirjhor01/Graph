#include<bits/stdc++.h>
using namespace std;
std::vector<int> par;
std::vector<int> vis;
std::vector<vector<int>> v;
int st, en;
int dfs(int node, int p){
	//cout << "NODE = " << node << '\n';
	vis[node] = 1;
	par[node] = p;
	for(auto i: v[node]){
		if(i == p) continue;
		if(vis[i] == 1){
			st = i;
			en = node;
			//cout << "end_node " << en << '\n';
			return 1;
		}
		if(vis[i] == 0){
		if(dfs(i, node) == 1) return 1;
 
	   }
 
	}
	return 0;
 
}
int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n + 2);
	while(m--) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
 
	}
	int ok = 0;
	for(int i = 1; i <= n; ++i){
		vis.resize(n + 1, 0);
	    par.resize(n + 1);
	    if(vis[i] == 1) continue;
	 	if(dfs(i, -1) == 1){
			ok = 1;
			break;
		}
	}
	if(ok == 0){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	std::vector<int> ans;
	int keep = en;
	ans.push_back(en);
	while(keep != st){
		ans.push_back(par[keep]);
		keep = par[keep];
	}
	ans.push_back(en);
	cout << ans.size() << '\n';
	for(auto i: ans){
		cout << i << ' ';
	}
	cout << '\n';
 
}
