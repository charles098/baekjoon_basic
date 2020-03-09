// 백준 2447번 - 별 찍기 - 10
// 재귀함수를 써서 풀었다. 알고리즘은 다음과 같다
// 1. 먼저 star 배열에 모두 별을 찍는다
// 2. 재귀함수를 써서 N*N크기 배열을 9조각으로 나누고 중간 조각(2,2)의 배열을 모두 ' '로 바꿔준다
// 3. N이 1이 될때까지 반복한다
#include <iostream>
using namespace std;
char star[6562][6562];

void erase(int sr,int er, int sc, int ec) {
	int add = (er - sr + 1) / 3;
	for (int i = sr + add; i < sr + add * 2; i++) 
		for (int j = sc + add; j < sc + add * 2; j++)
			star[i][j] = ' ';

	if (add == 1)
		return;
	
	erase(sr, sr + add - 1, sc, sc + add - 1); // (1,1)
	erase(sr, sr + add - 1, sc + add, sc + add * 2 - 1); // (1,2)
	erase(sr, sr + add - 1, sc + add * 2, ec); // (1,3);

	erase(sr + add, sr + add * 2 - 1, sc, sc + add - 1); // (2,1)
	erase(sr + add, sr + add * 2 - 1, sc + add * 2, ec); // (2,3)

	erase(sr + add * 2, er, sc, sc + add - 1); // (3,1)
	erase(sr + add * 2, er, sc + add, sc + add * 2 - 1); // (3,2)
	erase(sr + add * 2, er, sc + add * 2, ec); // (3,3)
}

int main() {
	int N;
	for (int i = 0; i < 6562; i++)
		for (int j = 0; j < 6562; j++)
			star[i][j] = '*';

	cin >> N;
	erase(1, N, 1, N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << star[i][j];
		cout << '\n';
	}

	return 0;
}
