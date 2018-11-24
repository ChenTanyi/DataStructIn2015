#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

const int N = 10000, M = 1000000;

struct Edge
{
		int s, t, nxt;
} E[M];

int fa[N], V[N], Row[N], cnt = 0, n;

int Find(int x)
{
		int xx = x, tmp;
		while(fa[xx] != -1)
				xx = fa[xx];
		// xx -> root
		while(fa[x] != -1)
		{
				tmp = fa[x];
				fa[x] = xx;
				x = tmp;
		}
		return xx;
}

void Union(int x, int y)
{
		int xx = Find(x), yy = Find(y);
		if(xx != yy)
				fa[xx] = yy;
}


void addEdge(int s, int t)
{
		E[cnt].s = s, E[cnt].t = t;
		E[cnt].nxt = V[s], V[s] = cnt;
		++cnt;
		E[cnt].s = t, E[cnt].t = s;
		E[cnt].nxt = V[t], V[t] = cnt;
		++cnt;
}

void Smash(int p, int d)
{
		int pos;
		switch(d)
		{
				case 0 : 
						pos = p - Row[p];
						break;
				case 1 : 
						pos = p - Row[p] + 1;
						break;
				case 2 :
						pos = p + Row[p];
						break;
				case 3 : 
						pos = p + Row[p] + 1;
						break;
		}
		if(pos < 1 || pos > n * (n + 1) / 2 || Row[p] == Row[pos] || abs(Row[p] - Row[pos]) > 1)
				return;
		Union(p, pos);
		addEdge(p, pos);
		addEdge(pos, p);
}

bool vis[N];
int ans[N], tail = 0;
void DFS(int s, int t)
{
		// DFS -> least alphabetic order path from s to t
		int u = s;
		ans[tail++] = u;
		vis[u] = true;
		if(u == t)
		{
				for(int i = 0; i < tail; ++i)
						printf("%d ", ans[i]);
				printf("\n");
				exit(0);
		}
		for(int i = V[s]; i != -1; i = E[i].nxt)
		{
				int v = E[i].t;
				if(!vis[v])
						DFS(v, t);
		}
		vis[u] = false;
}

int main()
{
		int s, t;
		memset(fa, 0xFF, sizeof fa);
		memset(V, 0xFF, sizeof V);
		scanf("%d %d %d", &n, &s, &t);
		for(int i = 1; i <= n; ++i)
		{
				int prev = i * (i - 1) / 2;
				for(int j = prev + 1; j <= prev + i; ++j)
						Row[j] = i;
		}
		for(;;)
		{
				int p, d;
				scanf("%d %d", &p, &d);
				Smash(p, d);
				if(Find(s) == Find(t))
						break;
		}
		DFS(s, t);
}
