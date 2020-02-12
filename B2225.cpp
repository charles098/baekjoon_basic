#include <iostream>
using namespace std;

int main() {
	long int dp[201][201];
	int mod = 1000000000;
	int n, k, sum;
	cin >> n >> k;

	for (int i = 1; i <= 200; i++) {
		dp[1][i] = 1; 
		dp[i][0] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			sum = 0;
			for (int l = 0; l <= j; l++) {
				sum += dp[i - 1][l];
			}
			dp[i][j] = sum % mod;
		}
	}

	cout << dp[k][n];

	return 0;
}