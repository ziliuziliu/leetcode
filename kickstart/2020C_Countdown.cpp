#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
int T, N, K, x, ans = 0, pre = -1;
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        ans = 0; pre = -1;
        scanf("%d%d", &N, &K);
        for (int i=1;i<=N;i++) {
            scanf("%d", &x);
            if (x == 1 && pre == 2) { ans++; pre = -1;}
            else if (x == K) pre = K;
            else if (x == pre - 1) pre = x;
            else pre = -1;
        } 
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}