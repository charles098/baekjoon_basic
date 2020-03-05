// 백준 2667번 - 단지번호붙이기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// num - 아파트 배열, visit - 방문 여부 체크
int N, num[26][26], visit[26][26];
vector<int> Cnt;
int m_row[] = { 1,-1,0,0 }; // 행 이동
int m_col[] = { 0,0,1,-1 }; // 열 이동
char c; // 입력값이 char이기 때문.. 어차피 -'0'으로 정수형으로 바꿔줌

void dfs(int row, int col, int& cnt) {	
	// 방문했으면 넘어가기
	if (visit[row][col])
		return;
	// 방문 안했으면 우선 방문처리
	visit[row][col] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nrow = row + m_row[i]; // 새로운 행 인덱스
		int ncol = col + m_col[i]; // 새로운 열 인덱스
		// 새로운 행과 열이 정사각형 범위에 있으면
		if (nrow >= 1 && nrow <= N && ncol >= 1 && ncol <= N) {
			// 방문하지 않았고 아파트가 존재하면
			if (!visit[nrow][ncol] && num[nrow][ncol])
				dfs(nrow, ncol, cnt);
		}
	}
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) {
			cin >> c;
			num[i][j] = c - '0';
		}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			// num[i][j]이 1이고 아직 방문하지 않았으면
			if (num[i][j] && !visit[i][j]) {
				int count = 0;
				dfs(i, j, count);
				Cnt.push_back(count);
			}

		}
	}
	
	sort(Cnt.begin(), Cnt.end());
	cout << Cnt.size() << endl;
	for (int elem : Cnt)
		cout << elem << endl;

	return 0;
}
