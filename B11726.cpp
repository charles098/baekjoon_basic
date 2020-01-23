// 백준 11726번 - 2*n 타일링
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* d = new int[n + 1];
	d[0] = 1;
	d[1] = 1;

	for (int i = 2; i <= n; i++) 
		d[i] = (d[i - 1] + d[i - 2]) % 10007;

	cout << d[n];

	delete[] d;

	return 0;
}
