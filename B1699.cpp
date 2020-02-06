#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int dp[100001];
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 2; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}

	cout << dp[0];

	return 0;
}