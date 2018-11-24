#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>

const int D[4][2] = {{-1,-1},{-1,0},{1,0},{1,1}};
std::vector<int> f;
std::vector<int> ans;
std::vector<std::vector<int> > maze;
std::vector<std::pair<int, int> > num;
std::vector<bool> flag;
std::vector<std::set<int> > s;

int getf(int x){
	if (f[x] == x) return x;
	else return f[x] = getf(f[x]);
}

void dfs(int x, int n, const int& target, const int& tot){
	flag[x] = 0;
	if (static_cast<int>(ans.size()) <= n)
		ans.push_back(x);
	else ans[n] = x;
	if (x == target){
		for (int i = 0; i <= n ; ++ i){
			std::cout << ans[i] + 1 << (i == n? "\n" : " ");
		}
		exit(0);
	}
	for (std::set<int>::iterator it = s[x].begin(); it != s[x].end(); ++ it){
		if (flag[*it]){
			dfs(*it, n + 1, target, tot);
		}
	}
	flag[x] = 1;
}

void print(const std::vector< std::pair<int, int> > queue, int now){
	if (~now){
		print(queue, queue[now].second);
		std::cout << queue[now].first + 1 << (now == static_cast<int>(queue.size()) - 1 ? "\n" : " ");
	}
}

int main(){
	int n, a, b;
	//freopen("C:/Program Files (x86)/Notepad++/debug.in", "r", stdin);
	std::cin >> n >> a >> b;
	--a, --b;
	maze.resize(n);
	s.resize(n * (n + 1) / 2);
	int count = 0;
	for (int i = 0 ; i < n ; ++ i){
		for (int j = 0 ; j <= i ; ++ j){
			num.push_back(std::make_pair(i,j));
			maze[i].push_back(count);
			f.push_back(count++);
			flag.push_back(1);
		}
	}
	while (getf(f[a]) != getf(f[b])){
		int x, y;
		std::cin >> x >> y;
		-- x;
		int i = num[x].first, j = num[x].second;
		int tmpi = i + D[y][0], tmpj = j + D[y][1];
		if (0 <= tmpi && tmpi < n && 0 <= tmpj && tmpj <= tmpi){
			int tmp = maze[tmpi][tmpj];
			s[x].insert(tmp);
			s[tmp].insert(x);
			int fi = getf(x), fj = getf(tmp);
			if (fi != fj)
				f[fi] = fj;
		}
	}
	dfs(a, 0, b, n);
	/*std::vector< std::pair<int, int> > queue;
	queue.push_back(std::make_pair(a,-1));
	flag[a] = 0;
	for (int head = 0 ; head < static_cast<int>(queue.size()); ++ head){
		int now = queue[head].first;
		int x = num[now].first, y = num[now].second;
		for (int i = 0 ; i < 4; ++ i){
			int tmpx = x + D[i][0], tmpy = y + D[i][1];
			if (0 <= tmpx && tmpx < n && 0 <= tmpy && tmpy <= tmpx && flag[maze[tmpx][tmpy]]){
				flag[maze[tmpx][tmpy]] = 0;
				if (getf(now) == getf(maze[tmpx][tmpy]))
					queue.push_back(std::make_pair(maze[tmpx][tmpy], head));
				if (maze[tmpx][tmpy] == b){
					print(queue, queue.size() - 1);
					exit(0);
				}
			}
		}
	}*/
	return 0;
}