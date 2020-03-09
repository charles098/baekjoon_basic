// 백준 2448번 - 별 찍기-11
// 재귀함수로 시작점을 찾아가는 방식으로 풀었다. 계속 고민하다가 내 방식으로는 안돼서 블로그를 참고했다. 참신하면서도 굉장히 간단한 방법이다.
// 알고리즘은 아래와 같다
// 1. 모든 점을 다 공백처리
// 2. 시작점 세 개를 찾는다(위, 오른쪽 아래, 왼쪽 아래)
// 3. N이 3이 될때까지 반복하며, N==3이면 최소단위 별을 찍어준다
#include <iostream>
using namespace std;
char star[3073][6144];

void put(int n, int row, int col) {
	if (n == 3) {
		star[row][col] = '*';
		
		star[row + 1][col - 1] = '*';
		star[row + 1][col + 1] = '*';
		
		star[row + 2][col - 2] = '*';
		star[row + 2][col - 1] = '*';
		star[row + 2][col] = '*';
		star[row + 2][col + 1] = '*';
		star[row + 2][col + 2] = '*';
	}
	else {
		put(n / 2, row, col);
		put(n / 2, row + n / 2, col - n / 2);
		put(n / 2, row + n / 2, col + n / 2);
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= 2 * N - 1; j++)
			star[i][j] = ' ';

	put(N, 1, N); // (N, row, col);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2 * N - 1; j++)
			cout << star[i][j];
		cout << '\n';
	}

	return 0;
}
