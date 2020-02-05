// 백준 2579번 - 계단 오르기
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int dp[301];
	int a[301];
	int temp;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	dp[1] = a[1]; dp[2] = a[1] + a[2];
	dp[0] = 0;
	for (int i = 3; i <= n; i++) {
		temp = max(dp[i - 2] + a[i], dp[i - 1]);
		dp[i] = max(temp, dp[i - 3] + a[i - 1] + a[i]);
	}

	temp = max(dp[n - 2] + a[n], dp[n - 3] + a[n - 1] + a[n]);

	cout << temp;

	return 0;
}
