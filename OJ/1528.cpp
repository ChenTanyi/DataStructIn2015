#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <set>

long long target;
std :: vector < std :: multiset< std :: pair <long long, long long> > > v;
std :: vector < bool > f;

void dfs(long long node,long long length, long long& time, long long& flag){
	f[node] = 1;
	for (std::multiset<std::pair<long long,long long> >::iterator it = v[node].begin(); it != v[node].end(); ++ it){
		if (flag == 1) return;
		if (f[it->second]){
			continue;
		}
		time += it->first;
		if (it->second == target){
			std :: cout << time << "\n";
			exit(0);
		}
		dfs(it->second, it->first, time, flag);
		time += it->first;
	}
}

int main(){
	long long n;
	std :: cin >> n >> target;
	v.resize(n + 10);
	f.resize(n + 10, 0);
	for (long long i = 0 ; i < n - 1 ; ++ i){
		long long x, y, w;
		std :: cin >> x >> y >> w;
		v[x].insert(std::make_pair(w,y));
		v[y].insert(std::make_pair(w,x));
	}
	long long time = 0, flag = 0;
	if (target == 0){
		std :: cout << 0 << "\n";
		return 0;
	}
	dfs(0,-1,time,flag);
	std :: cout << time << "\n";
}