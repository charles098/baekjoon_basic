#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int dp[10001];
	int a[10001];
	int n;
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = a[i];
	}
	dp[0] = 0;
	
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + a[j]);
		
	cout << dp[n];

	return 0;
}