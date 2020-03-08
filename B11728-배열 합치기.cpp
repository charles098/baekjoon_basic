// 백준 11728번 - 배열 합치기
// 병합정렬을 이용하면 되기는 하나... cin.tie(0); ios::sync_with_stdio(false); 이게 없으면 시간초과가 뜬다. 시간 제한을 너무 엄격하게 잡은듯하다
// 아무리 생각해도 맞았는데 시간초과 나와서 블로그에 있는 코드를 그대로 복붙했는데 또 시간초과가 떴다....ㅡ,.ㅡ
// 다른 코드들을 비교하면서 cin.tie(0); ios::sync_with_stdio(false); 이에 대해 알게 되었다
#include <iostream>
using namespace std;

int n[1000000];
int m[1000000];

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++)
		cin >> n[i];
	for (int i = 0; i < M; i++)
		cin >> m[i];

	int ni = 0;
	int mi = 0;
	int ai = 0;

	while (ni < N && mi < M) {
		if (n[ni] < m[mi])
			cout << n[ni++] << " ";
		else
			cout << m[mi++] << " ";
	}

	while (ni < N)
		cout << n[ni++] << " ";
	while (mi < M)
		cout << m[mi++] << " ";

	return 0;
}
