#include <iostream>
#include <cstdio>
#include <set>

typedef std :: set <int> set;
set s;

int main(){
	std :: ios :: sync_with_stdio(false);
	int n;
	std :: cin >> n;
	for (int i = 0 ; i < n ; ++ i){
		char ch;
		int m;
		std :: cin >> ch >> m;
		int x;
		set :: iterator it;
		switch(ch){
		case '+':
			for (int j = 0 ; j < m ; ++ j){
				std :: cin >> x;
				s.insert(x);
			}
			break;
		case '-':
			for (int j = 0 ; j < m ; ++ j){
				std :: cin >> x;
				if ((it = s.find(x)) != s.end())
					s.erase(it);
			}
			break;
		case '*':
			set s2;
			for (int j = 0 ; j < m ; ++ j){
				std :: cin >> x;
				if (s.find(x) != s.end())
					s2.insert(x);
			}
			s = s2;
		}
		it = s.begin();
		if (it != s.end()) {
            std :: cout << *it++;
            for ( ; it != s.end() ; ++ it){
                std :: cout << " " << *it;
            }
		}
		std :: cout << "\n";
	}
	return 0;
}
