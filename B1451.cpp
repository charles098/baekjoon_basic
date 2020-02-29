#include <iostream>
using namespace std;

int N, M, rec[101][101];
long long max = 0;

long long sum(int s_col, int e_col, int s_row, int e_row) {
	long long t = 0;
	for (int i = s_row; i <= e_row; i++)
		for (int j = s_col; j <= e_col; j++)
			t += rec[i][j];
	return t;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			rec[i][j] = temp - '0';
		}
	}

	for (int i = 0; i < M - 2; i++) {
		for (int j = i + 1; j < M - 1; j++) {
			long long a = sum(0, i, 0, N - 1);
			long long b = sum(i + 1, j, 0, N - 1);
			long long c = sum(j + 1, M - 1, 0, N - 1);
			max = max > (a * b * c) ? max : (a * b * c);
		}
	}
	// 2번 case
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			long long a = sum(0, M - 1, 0, i);
			long long b = sum(0, M - 1, i + 1, j);
			long long c = sum(0, M - 1, j + 1, N - 1);
			max = max > (a * b * c) ? max : (a * b * c);
		}
	}

	// 위에 한 개, 아래 두 개
	for (int up = 0; up < N - 1; up++) {
		for (int dleft = 0; dleft < M - 1; dleft++) {
			long long a = sum(0, M - 1, 0, up);
			long long b = sum(0, dleft, up + 1, N - 1);
			long long c = sum(dleft + 1, M - 1, up + 1, N - 1);
			max = max > (a * b * c) ? max : (a * b * c);
		}
	}

	// 왼쪽 한 개, 오른쪽 두 개
	for (int left = 0; left < M - 1; left++) {
		for (int rup = 0; rup < N - 1; rup++) {
			long long a = sum(0, left, 0, N - 1);
			long long b = sum(left + 1, M - 1, 0, rup);
			long long c = sum(left + 1, M - 1, rup + 1, N - 1);
			max = max > (a * b * c) ? max : (a * b * c);
		}
	}

	// 오른쪽 한 개, 왼쪽 두 개
	for (int right = M - 1; right > 0; right--) {
		for (int lup = 0; lup < N - 1; lup++) {
			long long a = sum(right, M - 1, 0, N - 1);
			long long b = sum(0, right - 1, 0, lup);
			long long c = sum(0, right - 1, lup + 1, N - 1);
			max = max > (a * b * c) ? max : (a * b * c);
		}
	}

	// 아래 한 개, 위에 두 개
	for (int down = N - 1; down > 0; down--) {
		for (int uleft = 0; uleft < M - 1; uleft++) {
			long long a = sum(0, M - 1, down , N - 1);
			long long b = sum(0, uleft, 0, down - 1);
			long long c = sum(uleft + 1, M - 1, 0, down - 1);
			max = max > (a * b * c) ? max : (a * b * c);
		}
	}

	cout << max;

	return 0;
}