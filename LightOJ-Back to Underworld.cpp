#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
bool visit[N];
int color[N];
int cnt[2];
vector<int>adj[N];

void dfs(int node, int clr){
	if(visit[node] == 1) return;
	visit[node] = 1;
	color[node] = clr;
	cnt[color[node]]++;
	for(auto i: adj[node]){
		dfs(i, clr^1);
	}
	return;
}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int num;
		cin >> num;
		int x, y;
		memset(visit, 0, sizeof visit);
		memset(color, 0, sizeof color);
		for(int i = 0; i < N; i++){
			adj[i].clear();
		}
		int nu = num;
		vector<int>v;
		while(num--){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			v.push_back(x);
			v.push_back(y);
		}
		int ans = 0;
		for(int i = 0; i < v.size(); i++){
			dfs(v[i], 0);
			ans += max(cnt[0],cnt[1]);
			cnt[0] = 0;
			cnt[1] = 0;
		}
		cout << "Case " << i <<":" << " " << ans<< '\n';
		
	}
}
