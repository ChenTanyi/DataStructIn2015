#include <iostream>
#include <vector>

struct node{
	int p,l,r;
	node():p(0), l(0), r(0){}
};

int main(){
	int n, x, y;
	std::cin >> n >> x >> y;
	std::vector <node> v(n + 1);
	for (int i = 1 ; i <= n ; ++ i){
		std::cin >> v[i].l >> v[i].r;
		v[v[i].l].p = v[v[i].r].p = i;
	}
	int ans = x;
	while (v[ans].p != 0){
		int a = y;
		while (a && a != ans) a = v[a].p;
		if (a == ans) break;
		ans = v[ans].p;
	}
	std::cout << ans << "\n";
	return 0;
}