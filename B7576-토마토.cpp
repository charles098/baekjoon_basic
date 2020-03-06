// 백준 7576번 - 토마토
// 간단한 bfs 문제였지만 처음에 조금 해맸다..
#include <iostream>
#include <queue>
using namespace std;

int tom[1001][1001];
int col, row;
queue<pair<int, int>> q;
int m_row[] = { 1,-1,0,0 };
int m_col[] = { 0,0,1,-1 };

int main() {
	cin >> col >> row;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			cin >> tom[i][j];
			if (tom[i][j] == 1)
				q.push(make_pair(i, j));
		}

	while (!q.empty()) {
		pair<int, int> pos = q.front();
		int r = pos.first;
		int c = pos.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int rr = r + m_row[i];
			int cc = c + m_col[i];
			if (rr >= 1 && rr <= row && cc >= 1 && cc <= col) {
				if (!tom[rr][cc]) {
					q.push(make_pair(rr, cc));
					tom[rr][cc] = tom[r][c] + 1;
				}
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (!tom[i][j]) {
				cout << -1;
				return 0;
			}
			max = max > tom[i][j] ? max : tom[i][j];
		}
	}

	cout << max - 1; // 첫 시작이 1이라서 1빼준 결과가 정답이 된다

	return 0;
}
