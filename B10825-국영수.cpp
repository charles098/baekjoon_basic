// 백준 10825번 - 국영수
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Person {
	string name;
	int kor, eng, math;
};

bool cmp(Person a, Person b) {
	if(a.kor != b.kor)
		return a.kor > b.kor;
	else{
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
}

int main() {
	int N;
	cin >> N;
	vector<Person> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;

	sort(v.begin(), v.end(), cmp);

	for (Person elem : v)
		cout << elem.name << '\n';
	return 0;
}
