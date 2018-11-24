#include <iostream>
#include <vector>
#include <set>

struct node{
	int u, v, w;
	node(int x = 0, int y = 0, int value = 0):u(x), v(y), w(value){}
};

inline bool operator<(const node& a, const node& b){
	return a.w < b.w;
}

std::multiset<node> set;
std::vector<int> f;

int getf(int x){
	if (f[x] == x) return x;
	else return f[x] = getf(f[x]);
}

int main(){
	int n, m;
	std::cin >> n >> m;
	for (int i = 0 ; i <= n ; ++ i){
		f.push_back(i);
	}
	for (int i = 0 ; i < m ; ++ i){
		int x, y, w;
		std::cin >> x >> y >> w;
		set.insert(node(x, y ,w));
	}
	int count = 0, ans = 0;
	for (std::set<node>::iterator it = set.begin(); count < n - 1 && it != set.end(); ++ it){
		int x = it->u, y = it->v, w = it->w;
		int fx = getf(x), fy = getf(y);
		if (fx != fy){
			++ count;
			ans += w;
			f[fx] = fy;
		}
	}
	if (count == n - 1)
		std::cout << ans << "\n";
	return 0;
}