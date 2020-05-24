// 백준 7785번 - 회사에 있는 사람
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	set<string, greater<string>> s; // 사전 역순 출력을 위함
	set<string>::iterator iter;
	int count;
	string name, log;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> name >> log;
		iter = s.find(name);
		if (iter != s.end()) // 존재하는 경우
			s.erase(iter);
		else // 처음인 경우
			s.insert(name);
	}
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << '\n';

	return 0;
}
