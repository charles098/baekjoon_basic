// 백준 10844번 - 쉬운 계단 
#include <iostream>
using namespace std;

int d[101][10];

int main() {

	int n;
	long long sum = 0;
	const int mod = 1000000000;
	cin >> n;
	for (int j = 1; j < 10; j++)
		d[1][j] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 9) d[i][j] = d[i - 1][j - 1];
			else if (j == 0) d[i][j] = d[i - 1][j + 1];
			else d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod;
		}
	}

	for (int i = 0; i < 10; i++)
		sum += d[n][i];

	cout << sum % mod;

	return 0;
}
