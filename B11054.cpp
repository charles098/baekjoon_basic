#include <iostream>
using namespace std;

int main() {
	int dp[1001][2];
	int a[1001];
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][0] = dp[i][1] = 1;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (a[i] > a[j] && dp[j][1] + 1 > dp[i][1]) // dp[i][1] 은 증가하는 수열 
				dp[i][1] = dp[j][1] + 1;

	for (int i = n; 1 <= i; i--)
		for (int j = n; i < j; j--)
			if (a[i] > a[j] && dp[j][0] + 1 > dp[i][0]) // dp[i][0] 은 감소하는 수열
				dp[i][0] = dp[j][0] + 1;

	int max = 0;
	int sum;
	for (int i = 1; i <= n; i++) {
		sum = dp[i][0] + dp[i][1];
		max = max > sum ? max : sum;
	}

	cout << max - 1;

	return 0;
}