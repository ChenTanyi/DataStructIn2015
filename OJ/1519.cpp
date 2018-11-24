#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

const int E = 26;
const int N = 1E5 + 100;
char buffer[N];
int tot = 1, count = 0, left[N], right[N], ans[N], strnode[N];

int lowbit(int x){return x & (-x);}

struct ask{
	int x, y, num;
	ask(int a, int b, int c):x(a), y(b), num(c){}
	friend bool operator <(const ask & a, const ask & b){return a.y < b.y;}
};

std :: vector<ask> query;

struct node{
	std :: vector<node*> next;
	node *fail, *fa;
	int x;
	node(int num, int _x = 0 , node* f = 0):x(_x), fa(f){next.resize(num, 0);fail = 0;}
}*tire;

struct tree{
	std :: vector<int> next, edge, pre;
	void set(int m){pre.resize(m, -1);}
	void addedge(int x, int y){
		edge.push_back(y);
		next.push_back(pre[x]);
		pre[x] = next.size() - 1;
	}
}fail;

struct BIT{
	std :: vector<int> v;
	const int lim;
	BIT(int x):lim(x) {v.resize(x + 1, 0);}
	void Modify(int x, int c){
		for (; x <= lim ; x += lowbit(x))
			v[x] += c;
	}
	int Query(int x){
		int ret = 0;
		for (; x ; x -= lowbit(x))
			ret += v[x];
		return ret;
	}
};

void insert(node* & parent, char c){
	if (parent -> next[c - 'a'] == 0) parent -> next[c - 'a'] = new node(E, ++tot, parent);
	parent = parent -> next[c - 'a'];
}

int lim = 0;

void dfs(int x, int parent){
	left[x] = ++lim;
	for (int p = fail.pre[x] ; ~p ; p = fail.next[p]){
		if (fail.edge[p] != parent) dfs(fail.edge[p], x);
	}
	right[x] = lim;
}

void buildfail(node* root){
	std :: vector<node*> q;
	for (int i = 0 ; i < E ; ++ i){
		if (root -> next[i]) {
            q.push_back(root -> next[i]);
            root -> next[i] -> fail = root;
            fail.addedge(root -> x, root -> next[i] -> x);
		}
	}
	for (int head = 0 ; head < static_cast<int>(q.size()) ; ++ head){
		node* now = q[head];
		for (int i = 0 ; i < E ; ++ i){
			if (now -> next[i]){
				node* y = now -> next[i];
				q.push_back(y);
				node* p = now -> fail;
				while (p != root && !p -> next[i]) p = p -> fail;
				if (!p -> next[i]){
					y -> fail = root;
				}
				else y -> fail = p -> next[i];
				fail.addedge(y -> fail -> x, y -> x);
			}
		}
	}
}

int main(){
	std :: ios :: sync_with_stdio(false);
	std :: cin >> buffer;
	tire = new node(E, tot);
	tire -> fa = tire; tire -> fail = tire;
	node * now = tire;
	for (int i = 0 ; buffer[i]; ++ i){
		switch(buffer[i]){
			case 'P':strnode[++ count] = tot;break;
			case 'B':now = now -> fa;break;
			default:insert(now, buffer[i]);
		}
	}
	fail.set(tot + 1);
	buildfail(tire);
	dfs(tire -> x, 0);
	int m;
	std :: cin >> m;
	for (int i = 0 ; i < m ; ++ i){
		int x, y;
		std :: cin >> x >> y;
		query.push_back(ask(x,y,i));
	}
	std :: sort(query.begin(), query.end());query.push_back(ask(0,0,m + 1));
	now = tire;
	BIT bit(lim);
	int head = 0 , times = 0;
	for (int i = 0 ; buffer[i] ; ++ i){
		switch(buffer[i]){
			case 'B':bit.Modify(left[now -> x], -1); now = now -> fa;break;
			case 'P':
				++ times;
				while (query[head].y == times){
					int x = strnode[query[head].x];
					ans[query[head].num] = bit.Query(right[x]) - bit.Query(left[x] - 1);
					++ head;
				}
				break;
			default: now = now -> next[buffer[i] - 'a']; bit.Modify(left[now -> x], 1);
		}
	}
	for (int i = 0 ; i < m ; ++ i){
		std :: cout << ans[i] << "\n";
	}
	return 0;
}
