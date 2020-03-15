// 백준 11652번 - 카드
#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100000];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	long long answer = arr[0];
	int count_ans = 1, count = 1;

	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i - 1])
			count++;
		else
			count = 1;
		if (count_ans < count) {
			count_ans = count;
			answer = arr[i];
		}
	}

	cout << answer;

	return 0;
}
