// 백준 2146번 - 다리 만들기
// int curSize = q.size();
// for (int i = 0; i < curSize; i++){ ~
// 이 부분 때문에 두 시간을 날렸다. 큐는 pop을 하기 때문에 초기 큐 사이즈를 저장해줘야 한다. 
// 문제의 큰 알고리즘은 다음과 같다.
// 1. 섬마다 번호를 부여한다
// 2. 섬마다 모든 지점을 큐에 넣고 탐색한다
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int visit[101][101], map[101][101];
int m_row[] = { 1,-1,0,0 };
int m_col[] = { 0,0,1,-1 };
int N;

void dfs_remap(int row, int col, int island){
	visit[row][col] = true;
	map[row][col] = island; //몇번 섬인지 표시
	for (int i = 0; i < 4; i++) {
		int r = row + m_row[i];
		int c = col + m_col[i];
		if (1 <= r && r <= N && 1 <= c && c <= N)
			if (map[r][c] && !visit[r][c])
				dfs_remap(r, c, island);
	}
}

int bfs(int island) {
	queue<pair<int, int>> q;
	//우선 해당 섬의 좌표를 다 큐에 넣는
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (map[i][j] == island){
				visit[i][j] = true;
				q.push(make_pair(i, j));
			}

	int result = 0;
	while (!q.empty()){
		int curSize = q.size();
		//현재 큐에 있는 칸으로부터 한칸씩 전진해본다
		for (int i = 0; i < curSize; i++){
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++){
				int r = row + m_row[i];
				int c = col + m_col[i];
				//범위 내에 있고
				if (1 <= r && r <= N && 1 <= c && c <= N){
					//다른 섬에 도착할 경우 반환
					if (map[r][c] && map[r][c] != island)
						return result;
					//아직 방문하지 않은 바다칸이면 방문했다고 표시 후 큐에 넣는다
					else if (!map[r][c] && !visit[r][c]){
						visit[r][c] = true;
						q.push(make_pair(r, c));
					}
				}
			}
		}
		result++;
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	int cnt = 1;
	//DFS를 통해 섬 표시
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (map[i][j] && !visit[i][j])
				dfs_remap(i, j, cnt++);
	int result = 100000000;
	//각 섬에서 제일 가까운 섬까지 다리 놓을 때 최소 길이 구한다
	for (int i = 1; i < cnt; i++) {
		memset(visit, false, sizeof(visit));
		result = min(result, bfs(i));
	}
	cout << result << endl;
	return 0;
}
