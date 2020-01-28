// 백준 9465번 - 스티커
#include <iostream>
#include <algorithm>
using namespace std;

int d[2][100001];
int sum[2][100001];

int main() {
	int count;
	int n;
	int num;

	cin >> count;

	for (int a = 0; a < count; a++) { // 시행 횟수
		cin >> n; // n번째 시행
		for (int i = 0; i <= 1; i++) { // n번째 배열 초기화
			for (int j = 1; j <= n; j++) {
				cin >> num;
				d[i][j] = num;
			}
		}

		//알고리즘 시작
		sum[0][1] = d[0][1]; sum[1][1] = d[1][1];
		sum[0][0] = sum[1][0] = 0;
		for (int i = 2; i <= n; i++) {
			sum[0][i] = max(sum[1][i - 1], sum[1][i - 2]) + d[0][i];
			sum[1][i] = max(sum[0][i - 1], sum[0][i - 2]) + d[1][i];
		}
		cout << max(sum[0][n], sum[1][n]) << endl;
	}

	return 0;
}
