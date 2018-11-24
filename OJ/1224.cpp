#include <iostream>
#include <map>
#include <vector>

int main(){
	std :: ios :: sync_with_stdio(false);
	int n;
	std :: cin >> n;
	std :: vector<int> a(n), b(n), c(n), d(n);
	for (int i = 0 ; i < n ; ++ i){
		std :: cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	std :: map<int,int> m;
	for (int i = 0 ; i < n ; ++ i){
		for (int j = 0 ; j < n ; ++ j){
			++m[a[i] + b[j]];
		}
	}
	long long ans = 0;
	for (int i = 0 ; i < n ; ++ i){
		for (int j = 0 ; j < n ; ++ j){
			ans += m[-c[i]-d[j]];
		}
	}
	std :: cout << ans << "\n";
	return 0;
}