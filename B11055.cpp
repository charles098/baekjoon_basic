#include <iostream>
using namespace std;

int main() {
	int dp[1001];
	int a[1001];

	int n; int value;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = a[i];
	}

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j < i; j++) 
			if (a[i] > a[j])
				dp[i] = dp[j] + a[i];
	
	int max = 0;
	for (int i = 1; i <= n; i++) 
		max = max > dp[i] ? max : dp[i];
	
	cout << max;

	return 0;
}