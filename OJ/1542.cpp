#include <iostream>
#include <vector>

long long ans = 0;

void mergeSort(std::vector<int>& v, int l, int r, std::vector<int>& temp){
	if (l < r){
		int mid = (l + r) / 2;
		mergeSort(v,l, mid, temp);
		mergeSort(v,mid + 1, r, temp);
		int i = l, j = mid + 1, k = 0;
		while (i <= mid && j <= r){
			if (v[i] <= v[j]){
				temp[k++] = v[i++];
			}
			else {
				temp[k++] = v[j++];
				ans += mid - i + 1;
			}
		}
		while (i <= mid)
			temp[k++] = v[i++];
		while (j <= r)
			temp[k++] = v[j++];
		for (int i = 0 ; i < k ; ++ i){
			v[l + i] = temp[i];
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<int> v(n), temp(n);
	for (int i = 0 ; i < n ; ++ i){
		std::cin >> v[i];
	}
	mergeSort(v,0,n - 1,temp);
	std::cout << ans << "\n";
	return 0;
}