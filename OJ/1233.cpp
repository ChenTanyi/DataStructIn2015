#include <iostream>
#include <vector>
#include <set>

int ans = 0;

std::vector< std::multiset<int> > v;

void dfs(int x, int n, std::vector<bool>& flag){
	if (!n)
		++ ans;
	else {
		for (std::multiset<int>::iterator it = v[x].begin(); it != v[x].end(); ++ it){
			if (!flag[*it]){
				flag[*it] = 1;
				dfs(*it, n - 1, flag);
				flag[*it] = 0;
			}
		}
	}
}

int main(){
	int n, m, s, count;
	std::cin >> n >> m >> s >> count;
	v.resize(n + 1);
	for (int i = 0 ; i < m ; ++ i){
		int x, y;
		std::cin >> x >> y;
		v[x].insert(y);
	}
	std::vector<bool> flag(n + 1, 0);
	flag[s] = 1;
	dfs(s, count, flag);
	std::cout << ans << "\n";
	return 0;
}
