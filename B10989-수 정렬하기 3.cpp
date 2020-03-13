// 백준 10989번 - 수 정렬하기 3
// counting 정렬을 공부할 수 있는 문제이다. 처음 알았다. 시간복잡도가 O(n)으로 굉장히 빠르다.
#include <stdio.h>
 
int count[10001];
int main(){
    int n, i, input;
    scanf("%d", &n);
    for (i = 0;i<n;i++) {
        scanf("%d",&input);
        count[input]++;
    }
    for (i = 1;i < 10001;i++)
        if(count[i]) 
            for (int t = 0;t < count[i];t++)
                printf("%d\n",i);
}
