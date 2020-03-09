// 백준 1992번 - 쿼드트리
// 재귀함수를 써서 풀었다(분할정복)
#include <iostream>
using namespace std;

int arr[65][65];
int N;

bool one_number(int sr, int er, int sc, int ec) {
	int number = arr[sr][sc];
	for (int i = sr; i <= er; i++) 
		for (int j = sc; j <= ec; j++) 
			if (arr[i][j] != number)
				return false;
	return true;
}

void quad(int sr, int er, int sc, int ec) {
	if (one_number(sr, er, sc, ec)) {
		if (arr[sr][sc] == 1)
			cout << 1;
		else if (arr[sr][sc] == 0)
			cout << 0;
	}
	else {
		cout << '(';
		int add = (er - sr + 1) / 2;
		quad(sr, sr + add - 1, sc, sc + add - 1);
		quad(sr, sr + add - 1, sc + add, ec);
		quad(sr + add, er, sc, sc + add - 1);
		quad(sr + add, er, sc + add, ec);
		cout << ')';
	}
}

int main() {
	cin >> N;
	char c;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> c;
			arr[i][j] = c - '0';
		}

	quad(1, N, 1, N);

	return 0;
}
