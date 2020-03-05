// 백준 4963번 - 섬의 개수
#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

int N, M, num[51][51], visit[51][51];
int m_row[] = { 1,1,1,0,0,-1,-1,-1 };
int m_col[] = { 0,1,-1,1,-1,0,1,-1 };

void dfs(int row, int col) {
	if (visit[row][col])
		return;
	visit[row][col] = true;
	for (int i = 0; i < 8; i++) {
		int nrow = row + m_row[i];
		int ncol = col + m_col[i];
		if (nrow >= 1 && nrow <= M && ncol >= 1 && ncol <= N)
			if (!visit[nrow][ncol] && num[nrow][ncol])
				dfs(nrow, ncol);
	}
}

int main() {
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		memset(num, false, sizeof(num));
		memset(visit, false, sizeof(visit));

		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
				cin >> num[i][j];

		int count = 0;
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (num[i][j] && !visit[i][j]) {
					count++;
					dfs(i, j);
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}
