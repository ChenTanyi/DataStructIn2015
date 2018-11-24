#include <iostream>
#include <cstdio>
#include <map>
#include <string>

const int N = 100;
/*
struct charCmp{
	bool operator()(const char* a, const char* b){
		while (*a && *b){
			if (*a != *b) return *a < *b;
			++a, ++b;
		}
		if (*a) return 0;
		return 1;
	}
};*/

int main(){
	std::map<std::string, int> map;
	int n;
	char buffer[N];
	for (n = 0; gets(buffer) ; ++ n){
		++map[buffer];
	}
	for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); ++ it){
		printf("%s %.4f\n", it->first.c_str(), static_cast<double>(it->second) / n * 100);
	}
	return 0;
}