// 백준 2875번 - 대회 or 인턴
#include <iostream>
using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	while (n != 2 * m) {
		if (k == 0) break;

		if (n > 2 * m) {
			k--;
			n--;
		}
		else if(n < 2 * m){
			k--;
			m--;
		}
	}

	if (k == 0) {
		if (n >= 2 * m) cout << m;
		else cout << n / 2;
	}
	else {
		if (k % 3 == 0)
			cout << m - (k / 3);
		else
			cout << m - (k / 3) - 1;
	}
	return 0;
}
