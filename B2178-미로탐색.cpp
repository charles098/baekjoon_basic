// 백준 2178번 - 미로 탐색
// 전형적인 bfs문제
#include <iostream>
#include <queue>
using namespace std;

int maze[101][101];
int m_row[] = { 1,-1,0,0 };
int m_col[] = { 0,0,1,-1 };
int row, col;
char c;
queue<pair<int, int>> q;

int main() {
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> c;
			maze[i][j] = c - '0';
		}
	}
			
	q.push(make_pair(1, 1));

	while (!q.empty()) {
		pair<int,int> pos = q.front();
		int r = pos.first;
		int c = pos.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int rr = r + m_row[i];
			int cc = c + m_col[i];
			if (rr >= 1 && rr <= row && cc >= 1 && cc <= col) {
				if (maze[rr][cc] == 1) {
					q.push(make_pair(rr, cc));
					maze[rr][cc] = maze[r][c] + 1;
				}
			}
		}
	}
	cout << maze[row][col];
	return 0;
}
