// Connnected Component print from a Certain node.
#include<bits/stdc++.h>
using namespace std;
bool vis[100];
std::vector<int> adj[100];
void dfs(int node){
	if(vis[node] == 1) return;
	vis[node]= 1;
	cout << node << ' ';
	for(auto i: adj[node]){
		dfs(i);
	}
	return;
}
int main(){
	for(int i = 0; i < 100; i++) vis[i] = 0;
	int n, m;
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; i++){
    	cin >> x >> y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    dfs(8);
}
