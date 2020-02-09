#include <iostream>
using namespace std;

int main() {
	int dp[101];
	int n;
	cin >> n;
	int* a = new int[n + 1];
	int value;
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int i = 6; i <= 100; i++) 
		dp[i] = dp[i - 1] + dp[i - 5];
	
	
	for (int i = 1; i <= n; i++) {
		cin >> value;
		a[i] = dp[value];
	}

	for (int i = 1; i <= n; i++)
		cout << a[i] << endl;

	return 0;
}