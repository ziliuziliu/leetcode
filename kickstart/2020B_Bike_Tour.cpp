#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int T, n, h[maxn], ans;
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        scanf("%d", &n); ans = 0;
        for (int i=1;i<=n;i++) scanf("%d", &h[i]);
        for (int i=2;i<n;i++) ans += (h[i] > h[i-1] && h[i] > h[i+1]);
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}