// 백준 2133번 - 타일 채우기
#include <iostream>
using namespace std;

int main() {
	int n;
	int dp[31] = {1, 0, 3};
	cin >> n;

	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = 3 * dp[i - 2];
			for (int j = 2; j <= i - 2; j += 2) {
				dp[i] += 2 * dp[i - 2 - j];
			}
		}
	}

	cout << dp[n];

	return 0;
}
