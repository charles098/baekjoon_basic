#include <iostream>
#include <set>
using namespace std;



int main() {
	set<string, greater<string>> s;
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
		cout << *iter << endl;

	return 0;
}