#include <iostream>
#include <set>
#include <utility>
#include <vector>

std::set< std::pair<int, int> > set;

int main(){
	int n, k;
	std::cin >> k >> n;
	std::vector<int> v(n);
	for (int i = 0 ; i < n ; ++ i){
		std::cin >> v[i];
		if (i < k)
			set.insert(std::pair<int, int>(v[i], i));
	}
	std::cout << set.rbegin()->first << " ";
	for (int i = k; i < n ; ++ i){
		std::set< std::pair<int, int> >::iterator it = set.find(std::pair<int,int>(v[i - k], i - k));
		set.erase(it);
		set.insert(std::pair<int, int>(v[i], i));
		std::cout << set.rbegin()->first;
		if (i == n - 1) std::cout << "\n";
		else std::cout << " ";
	}
	return 0;
}