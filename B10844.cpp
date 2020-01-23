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
			else d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod; // 여기서 %mod가 빠지면 틀리는데 이유가 뭐죠?
		}
	}

	for (int i = 0; i < 10; i++)
		sum += d[n][i];

	cout << sum % mod;

	return 0;
}