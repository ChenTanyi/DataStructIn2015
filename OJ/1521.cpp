#include <iostream>
#include <vector>
using std::vector;

vector<int> f, g, l;

struct tree{
	std :: vector<int> next, edge, pre;
	void set(int m){pre.resize(m, -1);}
	void addedge(int x, int y){
		edge.push_back(y);
		next.push_back(pre[x]);
		pre[x] = next.size() - 1;
	}
}v;

int dfs(int node, int fa){
	int max = 0, max2 = 0;
	for (int p = v.pre[node]; ~p ; p = v.next[p]){
		if (v.edge[p] == fa) continue;
		if (dfs(v.edge[p],node) + 1 > max){
			max = f[v.edge[p]] + 1;
			l[node] = v.edge[p];
		}
	}
	for (int p = v.pre[node]; ~p ; p = v.next[p]){
		if (v.edge[p] == fa) continue;
		if (f[v.edge[p]] + 1 > max2 && v.edge[p] != l[node]){
			max2 = f[v.edge[p]] + 1;
		}
	}
	g[node] = max2;
	return f[node] = max;
}

int main(){
	std :: ios :: sync_with_stdio(false);
	int n , m;
	std :: cin >> n >> m;
	v.set(n+m+10);
	f.resize(n + m + 10, -1);
	g.resize(n + m + 10, -1);
	l.resize(n + m + 10, -1);
	for (int i = 2; i <= n; ++ i){
		int x;
		std :: cin >> x;
		v.addedge(x,i);
		v.addedge(i,x);
	}
	for (int i = 0; i < m ; ++ i){
		int x;
		std :: cin >> x;
		v.addedge(x, n + i + 1);
		v.addedge(n + i + 1, x);
	}
	for (int i = 1 ; i <= n + m; ++ i){
		if (!~f[i])
			f[i] = dfs(i,0);
	}
	int ans = 0;
	for (int i = 1 ; i <= n + m ; ++ i){
		if (ans < f[i] + g[i])
			ans = f[i] + g[i];
	}
	std :: cout << ans << "\n";
	return 0;
}
