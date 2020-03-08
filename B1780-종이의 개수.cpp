// 백준 1780번 - 종이의 개수
// 재귀함수를 써서 풀었다
#include <iostream>
using namespace std;

int arr[2188][2188];
int N, a = 0, b = 0, c = 0;

bool one_number(int sr, int er, int sc, int ec) {
	int num = arr[sr][sc]; // 처음 숫자
	for (int i = sr; i <= er; i++) {
		for (int j = sc; j <= ec; j++) {
			if (num != arr[i][j])
				return false;
		}
	}
	return true;
}

void divide(int sr, int er, int sc, int ec) {
	if (one_number(sr, er, sc, ec)) {
		if (arr[sr][sc] == -1)
			a += 1;
		else if (arr[sr][sc] == 0)
			b += 1;
		else if (arr[sr][sc] == 1)
			c += 1;
	}
	else { // 총 9조각을 내야한다
		int add = (er - sr + 1) / 3;
		// 첫번째 행
		divide(sr, sr + add - 1, sc, sc + add - 1);
		divide(sr + add, sr + add * 2 - 1, sc, sc + add - 1);
		divide(sr + add * 2, er, sc, sc + add - 1);
		
		// 두번째 행
		divide(sr, sr + add - 1, sc + add, sc + add * 2 - 1);
		divide(sr + add, sr + add * 2 - 1, sc + add, sc + add * 2 - 1);
		divide(sr + add * 2, er, sc + add, sc + add * 2 - 1);
		
		// 세번째 행
		divide(sr, sr + add - 1, sc + add * 2, ec);
		divide(sr + add, sr + add * 2 - 1, sc + add * 2, ec);
		divide(sr + add * 2, er, sc + add * 2, ec);
	}	
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	
	divide(1, N, 1, N);

	cout << a << '\n'; // -1 개수
	cout << b << '\n'; // 0 개수
	cout << c << '\n'; // 1 개수

	return 0;
}
