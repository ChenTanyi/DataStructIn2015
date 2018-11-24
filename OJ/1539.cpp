#include <iostream>
#include <map>

long long ans = 0;
int queen[20], n;
std::map<int, int> map;

void dfs(int x, int col, int left, int right, int& target){
	if (x == n){
		++ans;
		if (ans <=3){
			for (int i = 0 ; i < n - 1 ; ++ i){
				std::cout << queen[i] << " ";
			}
			std::cout << queen[n - 1] << "\n";
		}
	}
	else {
		int p = target &  ~(col | left | right);
		while (p){
			int a = p & -p;
			p -= a;
			queen[x] = map[a];
			dfs(x + 1, col | a, (left | a) << 1, (right | a) >> 1, target);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	for (int i = 0 ; i < n ; ++ i){
		map[1 << i] = i + 1;
	}
	int target = (1 << n) - 1;
	dfs(0, 0, 0, 0, target);
	std::cout << ans << "\n";
	return 0;
}