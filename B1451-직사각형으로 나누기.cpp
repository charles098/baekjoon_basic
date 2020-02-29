// 백준 1451번 - 직사각형으로 나누기
#include <iostream>
using namespace std;

int N, M, rec[101][101];
long long Max = 0;

// 직사각형 안에 있는 숫자들 더해주는 함수
long long sum(int s_col, int e_col, int s_row, int e_row) {
	long long s = 0;
	for (int i = s_row; i <= e_row; i++)
		for (int j = s_col; j <= e_col; j++)
			s += rec[i][j];
	return s;
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

	// ↓↓↓ 인 경우
	for (int i = 0; i < M - 2; i++) {
		for (int j = i + 1; j < M - 1; j++) {
			long long a = sum(0, i, 0, N - 1);
			long long b = sum(i + 1, j, 0, N - 1);
			long long c = sum(j + 1, M - 1, 0, N - 1);
			Max = Max > (a * b * c) ? Max : (a * b * c);
		}
	}

	// →
	// →
	// → 인 경우
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			long long a = sum(0, M - 1, 0, i);
			long long b = sum(0, M - 1, i + 1, j);
			long long c = sum(0, M - 1, j + 1, N - 1);
			Max = Max > (a * b * c) ? Max : (a * b * c);
		}
	}

	// 왼쪽 한 개, 오른쪽 두 개
	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			long long a = sum(0, i, 0, N - 1);
			long long b = sum(i + 1, M - 1, 0, j);
			long long c = sum(i + 1, M - 1, j + 1, N - 1);
			Max = Max > (a * b * c) ? Max : (a * b * c);
		}
	}

	// 오른쪽 한 개, 왼쪽 두 개
	for (int i = M - 1; i > 0; i--) {
		for (int j = 0; j < N - 1; j++) {
			long long a = sum(i, M - 1, 0, N - 1);
			long long b = sum(0, i - 1, 0, j);
			long long c = sum(0, i - 1, j + 1, N - 1);
			Max = Max > (a * b * c) ? Max : (a * b * c);
		}
	}

	// 위에 한 개, 아래 두 개
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			long long a = sum(0, M - 1, 0, i);
			long long b = sum(0, j, i + 1, N - 1);
			long long c = sum(j + 1, M - 1, i + 1, N - 1);
			Max = Max > (a * b * c) ? Max : (a * b * c);
		}
	}

	// 아래 한 개, 위에 두 개
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < M - 1; j++) {
			long long a = sum(0, M - 1, i, N - 1);
			long long b = sum(0, j, 0, i - 1);
			long long c = sum(j + 1, M - 1, 0, i - 1);
			Max = Max > (a * b * c) ? Max : (a * b * c);
		}
	}

	cout << Max;

	return 0;
}
