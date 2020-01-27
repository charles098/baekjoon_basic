#include <iostream>
using namespace std;

int d[1001][10];

int main() {
	const int mod = 10007;
	int n;
	cin >> n;

	for (int j = 0; j < 10; j++)
		d[1][j] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			int sum1 = 0;
			for (int k = 0; k <= j; k++) {
				sum1 += d[i - 1][k];
			}
			d[i][j] = sum1 % mod;
		}
	}

	int sum2 = 0;
	
	for (int j = 0; j < 10; j++)
		sum2 += d[n][j];

	cout << sum2 % mod;

	return 0;
}
