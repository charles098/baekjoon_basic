// 백준 10610번 - 30
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string num, answer;
	int check_zero = 0;
	cin >> num;
	int sum = 0, size = num.length();
	
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = num[i] - '0';
		if (arr[i] == 0) check_zero++;
	}

	for (int i = 0; i < size; i++)
		sum += arr[i];

	if (check_zero == 0 || sum % 3 != 0)
		cout << -1;
	else {
		sort(arr, arr + size, greater<int>());
		for (int i = 0; i < size; i++)
			cout << arr[i];
	}
	
	return 0;
}
