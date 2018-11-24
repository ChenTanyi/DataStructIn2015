#include <iostream>
#include <cstdio>

int Year[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool checkLeap(int i){
	if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
		return 1;
	return 0;
}

int main(){
	int a , b , c , y1 , y2;
	std :: cin >> a >> b >> c >> y1 >> y2;
	--a;
	c %= 7;
	int ans = 2;
	for (int i = 1850 ; i < y1 ; ++ i){
		if (checkLeap(i))
			ans = (ans + 2) % 7;
		else ans = (ans + 1) % 7;
	}
	for (int i = y1 ; i <= y2 ; ++ i){
		int tmp = ans;
		if (checkLeap(i)) {Year[1] = 29;ans = (ans + 2) % 7;}
		else {Year[1] = 28; ans = (ans + 1) % 7;}
		for (int m = 0 ; m < a ; ++ m){
			tmp = (tmp + Year[m]) % 7;
		}
		int data = (c - tmp + 7) % 7;
		data += (b - 1) * 7 + 1;
		if (data > Year[a]) puts("none");
		else printf("%d/%02d/%02d\n",i,a+1,data);
	}
	return 0;
}