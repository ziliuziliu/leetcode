#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
int T, n, b, a[maxn];
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        scanf("%d%d", &n, &b);
        for (int i=1;i<=n;i++) scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        int ret = 0, ans = 0;
        for (int i=1;i<=n;i++) {
            if (ret + a[i] > b) break;
            ret += a[i];
            ans++;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}