// 백준 11047번 - 동전0
#include <iostream> 
using namespace std;

int main(){
	int n, k, index, count = 0;
	cin >> n >> k;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	index = n - 1;
	while (k != 0) {
		if (arr[index] > k) index--;
		else {
			k -= arr[index];
			count++;
		}
	}

	cout << count;
	delete[] arr;
	return 0;
}
