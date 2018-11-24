#include "Headers/Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
	srand(time(0));
	int n, k;
	std::cin >> n >> k;
	vector<int> v;
	for (int i = 0 ; i < n ; ++ i){
		v.push_back(rand());
		std::cout << v[i] << " ";
	}
	std::cout << "\n" << Sort<int>::firstSort(v.begin(), v.end(), k) << " " << Sort<int>::secondSort(v.begin(), v.end(), k) << "\n";
	return 0;
}
