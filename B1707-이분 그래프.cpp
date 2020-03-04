// 백준 1707번 - 이분 그래프
#include <iostream>
#include <vector>
using namespace std;
vector <int> link[20001];
int visit[20001];
int K, V, E, a, b;

void dfs(int start, int color)
{
	visit[start] = color;
	for (int i = 0; i < link[start].size(); i++)
	{
		int y = link[start][i];
		if (visit[y] == 0)
		{
			dfs(y, 3 - color);
		}
	}
}
int main() {
	cin >> K;
	for (int rep = 0; rep < K; rep++)
	{
		cin >> V >> E;
		bool is = true;
		for (int i = 1; i <= 20000; i++)
		{
			link[i].clear();
			visit[i] = 0;
		}
		for (int i = 0; i < E; i++)
		{
			cin >> a >> b;
			link[a].push_back(b);
			link[b].push_back(a);
		}
		for (int i = 1; i <= V; i++)
		{
			if (visit[i] == 0)
				dfs(i, 1);
		}
		for (int i = 1; i <= V; i++)
		{
			for (int j = 0; j < link[i].size(); j++)
			{
				int tmp = link[i][j];
				if (visit[i] == visit[tmp])
					is = false;
			}
		}
		printf("%s\n", is ? "YES" : "NO");
	}
    return 0;
}
