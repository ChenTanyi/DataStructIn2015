#include <iostream>
#include <cstdlib>

int n;
char ans[55];
int tot = 0, k;

void dfs(int num, int zero, int one, int three){
	if (num == n){
		if (zero && one && three)
			++ tot;
        if (tot == k){
			ans[n] = 0;
			std :: cout << ans << "\n";
			exit(0);
		}
	}
	else {
		if (!one){
			ans[num] = '0';
			dfs(num + 1, 1, one, three);
		}
		if (zero){
			ans[num] = '1';
			dfs(num + 1, zero, 1, three);
		}
		if (!three){
			ans[num] = '2';
			dfs(num + 1, zero, one, three);
		}
		ans[num] = '3';
		dfs(num + 1, zero, one, 1);
	}
}

int main(){
	std :: cin >> n >> k;
	ans[0] = '2';
	dfs(1, 0, 0, 0);
}
