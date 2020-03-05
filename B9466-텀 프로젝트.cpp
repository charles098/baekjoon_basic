// 백준 9466번 - 텀 프로젝트
// 사실상 어려운 문제는 아니지만 시간초과가 떠서 고생했다. 처음에 내가 했던 방식은 시간 복잡도가 N(O^2)였다.
// 시간을 줄이는게 개인적으로 너무 어려워서 답을 보고도 이해하는데 좀 걸렸다.
// 방문했지만 더이상 방문할 필요가 없는 노드인 경우가 순환 사이클이라는 것을 이해하는데 한참 걸렸다.
// https://jaimemin.tistory.com/674 여기를 참고했으며 사실상 코드는 거의 복사 붙여넣기식이다.
// 대신 제출할때는 내가 혼자 코딩해서 성공했다
#include <iostream>
#include <cstring>
using namespace std;

int stu[100001], visit[100001], done[100001];
int T, N, cnt;

void dfs(int node){
    visit[node] = 1;
    int next = stu[node];
    if(!visit[next])
        dfs(next);
    // 방문했지만 더이상 방문할 필요가 없는 노드인 경우
    else if(!done[next]){
        //팀원들을 모두 센다
        for(int i = next; i != node; i = stu[i])
            cnt++;
        cnt++;
    }
    done[node] = 1; // 더이상 방문할 필요 없음
}

int main(){
    cin >> T;
    for(int rep = 0; rep < T; rep++){
        // 초기화
        memset(visit, false, sizeof(visit));
		memset(done, false, sizeof(done));
        cnt = 0;
        
        cin >> N;
        for(int i = 1; i <= N ;i++)
            cin >> stu[i];
        
        for(int i = 1; i <= N; i++)
            if(!visit[i])
                dfs(i);
        
        cout << N - cnt << endl;
    }    
}
