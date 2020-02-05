// 백준 1912번 - 연속합
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int dp[100001];
	int a[100001];
	int temp;
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = a[i];
	}

	for (int i = 2; i <= n; i++) {
		temp = a[i];
		for (int j = i; j > 1; j--) {
			temp += a[j - 1];
			if (dp[i] < temp)
				dp[i] = temp;
		}
	}
	
	int m = dp[1];
	for (int i = 1; i < n; i++)
		m = max(m, dp[i + 1]);

	cout << m;
	return 0;
}
