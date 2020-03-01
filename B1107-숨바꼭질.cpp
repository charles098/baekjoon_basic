// 백준 1697번 - 숨바꼭질
// BFS알고리즘을 처음 사용해본 예제다. 원래 재귀함수로 풀려고 했으나 계속 실패해서 풀이를 보고 BFS를 공부했다.
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N, K;
    cin>>N>>K;

    int visit[100001] = {0,};
    queue<pair<int,int>> q;
    q.push(make_pair(N,0));

    while(!q.empty()){
        int f = q.front().first;
        int depth = q.front().second;

        if(f == K)
            break;

        q.pop();

        visit[f] = 1;

        if(f-1 >= 0 && !visit[f-1])
            q.push(make_pair(f-1, depth+1));
        if(f+1 <= 100000 && !visit[f+1])
            q.push(make_pair(f+1, depth+1));
        if(f*2 <= 100000 && !visit[f*2])
            q.push(make_pair(f*2, depth+1));
    }

    cout<<q.front().second;

    return 0;
}
