#include <iostream>
#include <vector>

typedef std::pair<int,int> PII;

const int inf = ~0u >> 2;
const int check = 1e7;

int main(){
	int n, m, start, end;
	std::cin >> n >> m >> start >> end;
	std::vector< std::vector<PII> > v(n + 1);
	for (int i = 0 ; i < m ; ++ i){
		int x, y, w;
		std::cin >> x >> y >> w;
		v[x].push_back(std::make_pair(w,y));
	}
	std::vector<int> dis(n + 1, inf), q;
	std::vector<bool> flag(n + 1, 0);
	q.push_back(start);
	dis[start] = 0;
	flag[start] = 1;
	for (int head = 0; head < static_cast<int>(q.size()) ; ++ head){
		if (head > check) return 1;
		int now = q[head];
		for (std::vector<PII>::iterator it = v[now].begin(); it != v[now].end(); ++ it){
			if (dis[it->second] > dis[now] + it->first){
				dis[it->second] = dis[now] + it->first;
				if (!flag[it->second]){
					q.push_back(it->second);
					flag[it->second] = 1;
				}
			}
		}
		flag[now] = 0;
	}
	std::cout << dis[end] << "\n";
	return 0;
}