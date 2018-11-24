#include <iostream>
#include <cstdio>

const int N = 1e3+111;

class bigint{
public:
	static const int base = 10000;
	int x[N];
	int cnt;
	bigint():cnt(1){
	    x[0] = 0;
	}
	bigint & operator = (const bigint & y){
	    cnt = y.cnt;
	    for (int i = 0 ; i < cnt ; ++ i){
            x[i] = y.x[i];
	    }
	    return *this;
	}
	bigint & operator *= (const int y){
		int temp = 0;
		for (int i = 0 ; i < cnt ; ++ i){
			x[i] *= y;
			x[i] += temp;
			temp = x[i] / base;
			x[i] %= base;
		}
		while (temp) {
			x[cnt++] = temp % base;
			temp /= base;
		}
		return *this;
	}
	bigint & operator += (const int y){
		x[0] += y;
		int temp = 0 , i = 0;
		while (temp || x[i] + temp >= base){
			x[i] += temp;
			temp = x[i] / base;
			x[i] %= base;
			++ i;
		}
		if (i > cnt) cnt = i;
		return *this;
	}
	bigint & operator += (const bigint & y){
		int temp = 0 , mcnt = std :: max(cnt , y.cnt);
		for (int i = 0 ; i < mcnt ; ++ i){
			x[i] += y.x[i] + temp;
			temp = x[i] / base;
			x[i] %= base;
		}
		while (temp){
			x[mcnt++] = temp % base;
			temp /= base;
		}
		cnt = mcnt;
		return *this;
	}
	bigint & operator -= (const bigint & y){
		int temp = 0 ;
		for (int i = 0 ; i < cnt ; ++ i){
			x[i] -= y.x[i] + temp;
			if (x[i] < 0){
				x[i] += base;
				temp = 1;
			}
			else temp = 0;
		}
		while (!x[cnt-1]) -- cnt;
		if (cnt < 1) cnt = 1;
		return *this;
	}
	bool operator <= (const bigint & y){
		if (cnt < y.cnt) return 1;
		if (cnt > y.cnt) return 0;
		for (int i = cnt ; i-- ; ){
			if (x[i] < y.x[i]) return 1;
			if (x[i] > y.x[i]) return 0;
		}
		return 1;
	}
};

char s[N];

int main(){
	gets(s);
	/*if (s[0] == '1' && s[1] == 0){
        std :: cout << 1 << "\n";
        return 0;
	}*/
	bigint ans;
	for (int i = 0 ; s[i] ; ++ i){
		ans *= 10;
		ans += s[i] - '0';
	}
	bigint a;
	a += 1;
	bigint tmp;
	tmp.x[0] = 1;
	while (a <= ans) {
        tmp = a;
        a *= 2;
	}
	ans -= tmp;
	ans *= 2;
	ans += 1;
	printf("%d",ans.x[ans.cnt - 1]);
	for (int i = ans.cnt - 1 ; i-- ; ){
		printf("%04d",ans.x[i]);
	}
	puts("");
	return 0;
}
