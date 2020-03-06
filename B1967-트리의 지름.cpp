// 백준 1967번 - 트리의 지름
// 완전 동일한 문제가 동일한 제목으로 있다
// 다른 '트리의 지름'문제를 복사해왔다. 다른점은 tree에서 from->to, to->from을 다 연결해줘야 한다는 것. 그 외에는 코드도 똑같다.
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, num;
	vector<int> a;
	vector<int> b{ 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274 };
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> num;
		a.push_back(b[num]);
	}

	for (int elem : a)
		cout << elem << endl;

	return 0;
}
