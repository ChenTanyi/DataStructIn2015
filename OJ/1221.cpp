#include <iostream>
#include <string>
#include <set>

std :: multiset <int> set;
std :: multiset <int>::iterator it;

int main(){
	std :: ios :: sync_with_stdio(false);
	int n;
	std :: cin >> n;
	for (int i = 0 ; i < n ; ++ i){
		std :: string s;
		int x;
		std :: cin >> s;
		std :: cin >> x;
		if (s == "insert"){
			set.insert(x);
		}
		else if (s == "delete"){
			it = set.find(x);
			if (it != set.end()) set.erase(it);
		}
		else if (s == "delete_less_than"){
			it = set.lower_bound(x);
			set.erase(set.begin(), it);
		}
		else if (s == "delete_greater_than"){
			it = set.upper_bound(x);
			set.erase(it, set.end());
		}
		else if (s == "delete_interval"){
			int w;
			std :: cin >> w;
			set.erase(set.upper_bound(x), set.lower_bound(w));
		}
		else if (s == "find"){
			it = set.find(x);
			if (it == set.end()){
				std :: cout << "N\n";
			}
			else std :: cout << "Y\n";
		}
		else {
			it = set.begin();
			while (-- x && it != set.end()){
				++it;
			}
			if (it == set.end()){
				std :: cout << "N\n";
			}
			else std :: cout << *it << "\n";
		}
	}
	return 0;
}