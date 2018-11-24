#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "../Headers/function.h"
#include "../Headers/hash.h"
#include "../Headers/vector.h"

bool check(int x){
	for (int i = 2 ; i < sqrt(x) + 1; ++i){
		if (x % i == 0) return 0;
	}
	return 1;
}

int main(){
	srand(time(0));
	int x, ans = 0;
	for (x = 25e3; !check(x) ; ++x);//ȡ����25e3����С����
	Hash<int, Identity<int> > hash(x);
	vector<int> v;
	for (int i = 0 ; i < 1e4 ; ++ i){//����û��ɾ�����������Բ����ʱ�临�Ӷ���Ѱ��һ��
		int x = rand(), count;
		v.push_back(x);
		hash.insert(x, count);
		ans += count;
	}
	std :: cout << ans / 1e4 << "\n";
    return 0;
}
