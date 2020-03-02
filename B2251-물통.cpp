// 백준 2251번 - 물통
// 마찬가지로 bfs문제다. 핵심은 a -> b로 물을 옮길 때 만약 a+b > B 라면 A = a + b - B, B = B 가 되고 a+b <= B라면 A = 0, B = a + b임
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visit[201][201][201];
vector<int> result;
int A, B, C;

int main() {
	cin >> A >> B >> C;

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), C));
	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (visit[a][b][c]) // 방문했으면 지니감
			continue;

		visit[a][b][c] = 1;

		if (a == 0) // 조건 충족하면 c 저장
			result.push_back(c);

		// a -> b
		if (a + b > B)
			q.push(make_pair(make_pair(a + b - B, B), c));
		else
			q.push(make_pair(make_pair(0, a + b), c));

		// a -> c
		if (a + c > C)
			q.push(make_pair(make_pair(a + c - C, b), C));
		else
			q.push(make_pair(make_pair(0, b), a + c));

		// b -> a
		if (b + a > A)
			q.push(make_pair(make_pair(A, a + b - A), c));
		else
			q.push(make_pair(make_pair(a + b, 0), c));

		// b -> c
		if (b + c > C)
			q.push(make_pair(make_pair(a, b + c - C), C));
		else
			q.push(make_pair(make_pair(a, 0), b + c));

		// c -> a
		if (c + a > A)
			q.push(make_pair(make_pair(A, b), a + c - A));
		else
			q.push(make_pair(make_pair(a + c, b), 0));

		// c -> b
		if (c + b > B)
			q.push(make_pair(make_pair(a, B), c + b - B));
		else
			q.push(make_pair(make_pair(a, c + b), 0));
	}

	sort(result.begin(), result.end());
	for (int elem : result)
		cout << elem << endl;

	return 0;
}
