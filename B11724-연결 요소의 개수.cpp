// 백준 11724번 - 연결 요소의 개수
// dfs와 bfs 두 가지 방법으로 모두 풀어보았다.
/* 이 부분이 핵심이다. i를 시작점으로 놓고 탐색하는데, 만약에 i를 방문안했으면 answer++ 해준다.
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			answer++;
			//dfs(i);
			bfs(i);
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visit[1001];
vector<int> link[5001];

/* dfs
void dfs(int start) {
	if (visit[start])
		return;
	visit[start] = true;
	for (int i = 0; i < link[start].size(); i++) {
		int y = link[start][i];
		dfs(y);
	}
}
*/

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		for (int i = 0; i < link[pos].size(); i++) {
			int y = link[pos][i];
			if(!visit[y]){
				visit[y] = true;
				q.push(y);
			}
		}
	}
}

int main() {
	int n, m, a, b;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			answer++;
			//dfs(i);
			bfs(i);
		}
	}
	
	cout << answer;

	return 0;
}
