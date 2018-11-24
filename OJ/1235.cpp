#include <iostream>
#include <functional>
#include <vector>
#include <queue>

typedef std::pair<int,int> PII;

const int inf = ~0u >> 2;

void print(const std::vector<int>& f, int now, const int target){
	if (now){
		print(f, f[now], target);
		std::cout << now << (now == target ? "\n" : " ");
	}
}

int main(){
	int n, m, start, end;
	std::cin >> n >> m >> start >> end;
	std::vector<std::vector<PII> > maze(n + 1);
	for (int i = 0; i < m ; ++ i){
		int x, y, w;
		std::cin >> x >> y >> w;
		maze[x].push_back(std::make_pair(w, y));
	}
	std::vector<int> dis(n + 1, inf), f(n + 1), len(n + 1, inf);
	std::vector<bool> flag(n + 1, 0);
	dis[start] = 0;
	f[start] = 0;
	len[start] = 0;
	std::priority_queue<PII, std::vector<PII>, std::greater<PII> > q;
	q.push(std::make_pair(0, start));
	while (!q.empty()){
		PII now = q.top(); q.pop();
		int x = now.second;
		if (flag[x]) continue;
		flag[x] = 1;
		for (std::vector<PII>::iterator it = maze[x].begin(); it != maze[x].end(); ++ it){
			if (dis[it->second] > dis[x] + it->first){
				f[it->second] = x;
				len[it->second] = len[x] + 1;
				dis[it->second] = dis[x] + it->first;
				q.push(std::make_pair(dis[it->second], it->second));
			}
			else if (dis[it->second] == dis[x] + it->first && len[it->second] > len[x] + 1){
				f[it->second] = x;
				len[it->second] = len[x] + 1;
			}
		}
	}
	std::cout << dis[end] << "\n";
	print(f, end, end);
	return 0;
}