// 백준 11725번 - 트리의 부모 찾기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> link[100001];
int visit[100001];
int parent_node[100001];
int N,a,b;

int main() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	visit[1] = 1;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		for (int i = 0; i < link[pos].size(); i++) {
			int y = link[pos][i];
			if (!visit[y]) {
				parent_node[y] = pos;
				q.push(y);
				visit[y] = 1;
			}
		}
	}

	for (int i = 2; i <= N; i++)
		printf("%d\n", parent_node[i]);

	return 0;
}
