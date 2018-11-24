#include <iostream>
#include <cstdio>

int A(int m , int n){
	while (m){
		if (n == 0) n = 1;
		else n = A(m,n-1);
		--m;
	}
	return n + 1;
}


int main(){
	int m , n;
	std :: cin >> m >> n;
	std :: cout << A(m,n) << std :: endl;
	return 0;
}