#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int> minus;
	vector<int> plus;

	int N, num;
	int check_zero = 0, one = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) check_zero++;
		if (num == 1) one++;
		if (num < 0) minus.push_back(num);
		if (num > 1) plus.push_back(num);
	}

	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());

	int result = 0;
	
	if (plus.size() % 2)
		plus.push_back(1);
	for (int i = 0; i < plus.size(); i += 2)
		result += (plus[i] * plus[i + 1]);
	
	if (minus.size() % 2)
		check_zero == 0 ? minus.push_back(1) : minus.push_back(0);
	for (int i = 0; i < minus.size(); i += 2)
		result += (minus[i] * minus[i + 1]);

	result += one;

	cout << result;

	return 0;
}