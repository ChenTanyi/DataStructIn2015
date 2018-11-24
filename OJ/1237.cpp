#include <iostream>
#include <vector>

std::vector< std::vector<int> > v;

int main(){
	int n, m;
	std::cin >> n >> m;
	v.resize(n + 1);
	std::vector<int> count(n + 1, 0);
	for (int i = 0 ; i < m ; ++ i){
		int x,y;
		std::cin >> x >> y;
		v[y].push_back(x);
		count[x] ++ ;
	}
	std::vector<std::pair<int, int> > q;
	int ans = 1;
	for (int i = 1 ; i <= n ; ++ i){
		if (count[i] == 0){
			q.push_back(std::make_pair(i,1));
		}
	}
	for (int head = 0 ; head < static_cast<int>(q.size()) ; ++ head){
		int x = q[head].first, len = q[head].second;
		if (len > ans) ans = len;
		for (int i = 0 ; i < static_cast<int>(v[x].size()) ; ++ i){
			count[v[x][i]] --;
			if (count[v[x][i]] == 0){
				q.push_back(std::make_pair(v[x][i], len + 1));
			}
		}
	}
	std::cout << ans << "\n";
	return 0;
}