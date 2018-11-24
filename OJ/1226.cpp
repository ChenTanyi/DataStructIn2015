#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	std :: ios :: sync_with_stdio(false);
	int n;
	std :: cin >> n;
	std :: vector <int> v;
	for (int i = 0 ; i < n ; ++ i){
		int x;
		std :: cin >> x;
		v.push_back(x);
	}
	std :: sort(v.begin(), v.end());
	for (int i = 0 ; i < n ; ++ i){
		std :: cout << v[i] << (i == n-1 ? "\n" : " ");
	}
	return 0;
}