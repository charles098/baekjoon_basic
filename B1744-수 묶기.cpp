// 백준 1744번 - 수 묶기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int> minus; // 음수 벡터 생성
	vector<int> plus; // 양수 벡터 생성

	int N, num;
	int check_zero = 0, one = 0; // 0이 하나라도 있는지 체크, 일의 개수를 파악하기 위한 변수
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) check_zero++;
		if (num == 1) one++;
		if (num < 0) minus.push_back(num);
		if (num > 1) plus.push_back(num);
	}

	sort(plus.begin(), plus.end(), greater<int>()); // 양수는 내림차순으로 정렬
	sort(minus.begin(), minus.end()); // 음수는 오름차순으로 정렬

	int result = 0; // 정답 변수
	
	if (plus.size() % 2) // 맨 앞부터 두 개씩 묶어주기 위해 크기가 홀수이면 끝에 1을 추가해준다
		plus.push_back(1);
	for (int i = 0; i < plus.size(); i += 2)
		result += (plus[i] * plus[i + 1]); // 앞에서 순서대로 두 개씩 묶는다
	
	if (minus.size() % 2) // 음수는 0이 하나라도 있으면 끝에 0추가, 아니면 1추가
		check_zero == 0 ? minus.push_back(1) : minus.push_back(0);
	for (int i = 0; i < minus.size(); i += 2)
		result += (minus[i] * minus[i + 1]);

	result += one; // 1의 개수만큼 정답에 더해준다

	cout << result;

	return 0;
}
