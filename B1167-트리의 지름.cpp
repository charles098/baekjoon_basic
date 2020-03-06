// 백준 1167번 - 트리의 지름
// 알고리즘 문제가 다 마찬가지겠지만 푸는 방식만 알면 크게 어렵지 않은 문제이다.
// 임의의 한 점을 시작점으로 놓고 트리를 그리면 트리의 지름은 제일 밑에 있는 노드들 중 두 노드 간 거리일 것이다.
// 여기서는 1을 시작점으로 놓고 우선 제일 거리가 먼 노드를 구했다.
// 그 다음에 제일 먼 노드로부터 다시 제일 먼 노드를 찾아 거리의 합을 구했다
// 모든 노드는 시작점이 될 수 있는게 중요하다. 처음에는 이 생각을 잘 못해서 시작점을 찾는 엉뚱한 짓을 했다.
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int,int>> link[100001];
int visit[100001];
int V, far, result;


void dfs(int node, int sum) {
	if (visit[node])
		return;
	visit[node] = true;

	if (result < sum) {
		result = sum;
		far = node;
	}

	for (int i = 0; i < link[node].size(); i++) {
		int next = link[node][i].first;
		int distance = link[node][i].second;
		dfs(next, sum + distance);
	}
}

int main() {
	cin >> V;
	int from, to, dis;
	for (int i = 1; i <= V; i++) {
		cin >> from;
		while (true) {
			cin >> to;
			if (to == -1)
				break;
			cin >> dis;
			link[from].push_back({to,dis});
		}
	}

	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	dfs(far, 0);

	cout << result;

	retu
