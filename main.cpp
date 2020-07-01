#include <iostream>
#include <utility>
#include <queue>
using namespace std;

struct dice {
	dice(int a, int b, int c, int d, int e, int f) :
		one(a), two(b), three(c), four(d), five(e), six(f) {}
	int one, two, three, four, five, six;
	pair<int, int> location;
	void transform(int direction);
	void move_location(int direction, int N, int M, bool& search);
};

void dice::transform(int direction) {
	dice temp(one, two, three, four, five, six);
	
	if (direction == 1) { // ������ ���
		one = temp.three;
		three = temp.six;
		four = temp.one;
		six = temp.four;
	}
	else if (direction == 2) { // ������ ���
		one = temp.four;
		three = temp.one;
		four = temp.six;
		six = temp.three;
	}
	else if (direction == 3) { // ������ ���
		one = temp.two;
		two = temp.six;
		five = temp.one;
		six = temp.five;
	}
	else if(direction == 4){ // ������ ���
		one = temp.five;
		two = temp.one;
		five = temp.six;
		six = temp.two;
	}
	cout << six << endl;
}

void dice::move_location(int direction, int N, int M, bool& search){
	if (direction == 1) { // ��
		location.second += 1;
		if (location.second >= M) {
			location.second -= 1;
			search = false;
		}
	}
	else if (direction == 2) { // ��
		location.second -= 1;
		if (location.second < 0) {
			location.second += 1;
			search = false;
		}
	}
	else if (direction == 3) { // ��
		location.first -= 1;
		if (location.first < 0) {
			location.first += 1;
			search = false;
		}
	}
	else if (direction == 4) { // ��
		location.first += 1;
		if (location.first >= N) {
			location.first -= 1;
			search = false;
		}
	}
}

int main() {
	// �ֻ��� �ʱ�ȭ
	dice d(0, 0, 0, 0, 0, 0);

	int N, M, x, y, K, dir;

	cin >> N >> M >> x >> y >> K;
	
	// �ֻ��� ��ġ ����
	d.location = { x, y };

	// �迭 ���� �Ҵ�
	int** map = new int* [N];
	for (int i = 0; i < N; i++)
		map[i] = new int[M];

	// ������ �� �Է�
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	
	queue<int> que;
	for (int i = 0; i < K; i++) {
		cin >> dir;
		que.push(dir);
	}

	bool search;
	while (!que.empty()) {
		dir = que.front();
		search = true;
		d.move_location(dir, N, M, search);
		x = d.location.first;
		y = d.location.second;
		if (search) {
			d.transform(dir);
			if (map[x][y] == 0) {
				map[x][y] = d.one;
			}
			else {
				d.one = map[x][y];
				map[x][y] = 0;
			}
		}
		que.pop();
	}

	// �Ҵ�����
	for (int i = 0; i < N; i++)
		delete[] map[i];
	delete[] map;

	return 0;
}