#include <iostream>
#include <cstdio>
#include <set>

typedef std :: set<int> set;
set s;

int main(){
	std :: ios :: sync_with_stdio(false);
	int n;
	std :: cin >> n;
	for (int i = 0 ; i < n ; ++ i){
		int x;
		std :: cin >> x;
		s.insert(x);
	}
	int m;
	std :: cin >> m;
	for (int i = 0 ; i < m ; ++ i){
		int x;
		std :: cin >> x;
		set :: iterator it = s.find(x);
		if (it != s.end()) std :: cout << "Y\n";
		else std :: cout << "N\n";
	}
	return 0;
}