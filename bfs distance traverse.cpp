#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	std::vector<vector<int>> v(n);
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
	}
	int st = 0;
	queue<int>q;
	q.push(st);
	vector<bool>visited(n, 0);
	vector<int>dis(n);
	dis[0] = 0;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(auto i: v[f]){
			if(visited[i] == 1) continue;
			q.push(i);
			dis[i] = dis[f] + 1;
			visited[i] = 1;
		}
	}
	for(auto i: dis){
		cout << i << ' ';
	}
	cout << '\n';
}
