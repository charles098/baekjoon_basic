//백준 11053번 - 가장 긴 증가하는 부분 수열
// 어려워서 많이 검색해봤다ㅠ
#include <iostream>
using namespace std;

int main() {
	int dp[1001];
	int a[1001];

	int n; int value;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j < i; j++) 
			if (a[i] > a[j] && (dp[j] + 1) > dp[i])
				dp[i] = dp[j] + 1;
	
	int max = 0;
	for (int i = 1; i <= n; i++) 
		max = max > dp[i] ? max : dp[i];
	
	cout << max;

	return 0;
}
