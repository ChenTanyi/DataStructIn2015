#include <iostream>

const int N = 1E6 + 111;
int n;
char order, code;
char s[N],ans[N];

void preorder(int node){
	if (node < n){
		std :: cout << s[node];
		preorder(2 * node + 1);
		preorder(2 * node + 2);
	}
}

void inorder(int node){
	if (node < n){
		inorder(2 * node + 1);
		std :: cout << s[node];
		inorder(2 * node + 2);
	}
}

void postorder(int node){
	if (node < n){
		postorder(2 * node + 1);
		postorder(2 * node + 2);
		std :: cout << s[node];
	}
}

void rpreorder(int node, int& num){
	if (node < n){
		ans[node] =  s[num++];
		rpreorder(2 * node + 1, num);
		rpreorder(2 * node + 2, num);
	}
}

void rinorder(int node, int& num){
	if (node < n){
		rinorder(2 * node + 1, num);
		ans[node] =  s[num++];
		rinorder(2 * node + 2, num);
	}
}

void rpostorder(int node, int& num){
	if (node < n){
		rpostorder(2 * node + 1, num);
		rpostorder(2 * node + 2, num);
		ans[node] = s[num++];
	}
}

int main(){
	std :: ios :: sync_with_stdio(false);
	int t;
	std :: cin >> t;
	for (int test = 0 ; test < t ; ++ test){
		std :: cin >> n;
		std :: cin >> order;
		if (order == 'I'){
			for (int i = 0 ; i < 6 ; ++ i){
				char ch;
				std :: cin >> ch;
			}
		}
		else{
			std :: cin >> order;
			if (order == 'R'){
				for (int i = 0 ; i < 6 ; ++ i){
					char ch;
					std :: cin >> ch;
				}
			}
			else {
				for (int i = 0 ; i < 7 ; ++ i){
					char ch;
					std :: cin >> ch;
				}
			}
		}
		std :: cin >> code;
		for (int i = 0 ; i < 5 ; ++ i){
			char ch;
			std :: cin >> ch;
		}
		for (int i = 0 ; i < n ; ++ i){
			std :: cin >> s[i];
		}
		if (code == 'E'){
			switch (order){
				case 'R' : preorder(0);break;
				case 'I' : inorder(0);break;
				case 'O' : postorder(0);break;
			}
			std :: cout << "\n";
		}
		else {
			int num = 0;
			switch(order){
				case 'R' : rpreorder(0,num);break;
				case 'I' : rinorder(0,num);break;
				case 'O' : rpostorder(0,num);break;
			}
			ans[n] = 0;
			std :: cout << ans << "\n";
		}
	}
	return 0;
}