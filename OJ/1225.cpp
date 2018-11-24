#include <iostream>
#include <set>

int main(){
	std :: ios :: sync_with_stdio(false);
	int n;
	std :: cin >> n;
	std :: set<int> s;
	for (int i = 0 ; i < n ; ++ i){
		int x;
		std :: cin >> x;
		s.insert(x);
	}
	std :: cout << s.size() << "\n";
	return 0;
}