// 백준 9019번 - DSLR
// 전형적인 bfs문제다
#include <iostream>
#include <queue> 
#include <string>
using namespace std;

int visit[10000];
int T, start, goal;

void init_visit() {
	for (int i = 0; i < 10000; i++)
		visit[i] = 0;
}

string bfs() {
	queue<pair<int, string>> q;
	q.push(make_pair(start, ""));
	visit[start] = 1;

	while (!q.empty()) {
		int pos = q.front().first;
		string change = q.front().second;
		q.pop();

		if (pos == goal)
			return change;

		//D
		int next = (2 * pos) % 10000;
		if (!visit[next]) {
			visit[next] = 1;
			q.push(make_pair(next, change + "D"));
		}

		//S
		next = (pos - 1) < 0 ? 9999 : pos - 1;
		if (!visit[next]) {
			visit[next] = 1;
			q.push(make_pair(next, change + "S"));
		}

		//L
		next = pos / 1000 + (pos % 1000) * 10;
		if (!visit[next]) {
			visit[next] = 1;
			q.push(make_pair(next, change + "L"));
		}

		//R
		next = (pos % 10) * 1000 + (pos / 10);
		if (!visit[next]) {
			visit[next] = 1;
			q.push(make_pair(next, change + "R"));
		}
	}
	cout << visit[goal];
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		init_visit();
		cin >> start >> goal;
		cout << bfs() << endl;
	}
	return 0;
}
