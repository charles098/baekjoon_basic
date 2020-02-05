// 백준 1912번 - 연속합
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int dp[100001];
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> dp[i];

	int m = dp[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] > 0 && dp[i] + dp[i - 1] > 0)
			dp[i] += dp[i - 1];
		
		m = max(m, dp[i]);
	}

	cout << m;
	return 0;
}
