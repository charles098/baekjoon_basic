#include <iostream>
#include <string>
using namespace std;

int main() {
	long int dp[5001] = { 0 };
	int a[5001];
	int compare, len, mod = 1000000;
	string num;
	dp[0] = 1;

	cin >> num;
	len = num.length();
	for (int i = 1; i <= len; i++)
		a[i] = num[i - 1] - '0';

	for (int i = 1; i <= len; i++) {
		if (a[i] >= 1 && a[i] <= 9)
			dp[i] += dp[i - 1];
		if (i == 1) continue;
		compare = a[i - 1] * 10 + a[i];
		if (compare >= 10 && compare <= 26)
			dp[i] += dp[i - 2];
	}

	if (a[1] == 0)
		cout << 0;
	else
		cout << dp[len] % mod;

	return 0;
}