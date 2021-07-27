// Link : https://www.urionlinejudge.com.br/judge/en/problems/view/1610
// code 
/* Author - Nguyen Quoc Khanh */
#include <bits/stdc++.h>
using namespace std;
int T,N,M,A,B;
bool ok;
// DFS
class Graph {
	public:
		vector<int> visited;
		vector<vector<int>> adj;
		Graph(int n) {
			adj.assign(n,vector<int>());
			visited.assign(n,0);
		}
		void addEdge(int u,int v) {
			adj[u-1].push_back(v-1);
		}
		void DFSUntil(int v){
			visited[v] = 1;
			if(ok) return;
			for(int i = 0;i < adj[v].size();i++) {
				if(visited[adj[v][i]]==1) {
					ok = true;
					return;
				}
				else if(visited[adj[v][i]]==0) {
					DFSUntil(adj[v][i]);
				}
			}
			visited[v] = 2;
		} // reachable from v
		void DFS(int n){
				for(int i = 0;i<n;i++) {
					if(!visited[i]) DFSUntil(i);
					if(ok) break;
				}
			}
		~Graph(){
			visited.clear();
			adj.clear();
		}
};
void solve() {	  
	cin>>N>>M;
	Graph g(N);
	while (M--){
		cin>>A>>B;	
		g.addEdge(A,B);
	}
	ok = false;
	g.DFS(N);
	if(ok) cout << "SIM" << endl;	
	else cout << "NAO" << endl;
}
/*-------------------------------------------------------------------------*/
int main() { 
	scanf("%d",&T);
	while (T--)
	{
		solve();
	}
	return 0;
}	
