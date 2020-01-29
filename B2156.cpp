#include <iostream>
#include <algorithm>
using namespace std;

int d[10001];
int sum[10001];

int main() {
	int n;
	int value;
	int temp;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> value;
		d[i] = value;
	}

	sum[0] = 0; sum[1] = d[1]; sum[2] = d[1] + d[2];
	for (int i = 3; i <= n; i++) {
		temp = max(sum[i - 3] + d[i - 1] + d[i], sum[i - 2] + d[i]);
		sum[i] = max(temp, sum[i - 1]);
	}

	cout << sum[n];

	return 0;
}