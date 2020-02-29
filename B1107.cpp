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