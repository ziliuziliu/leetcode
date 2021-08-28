#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
int T, n, v[maxn], mx = -1, ans = 0;
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        mx = -1; ans = 0; memset(v, 0, sizeof(v));
        scanf("%d", &n);
        for (int i=1;i<=n;i++) scanf("%d", &v[i]); v[n+1] = -1;
        for (int i=1;i<=n;i++) {
            if (v[i] > mx && v[i] > v[i+1]) ans++;
            mx = max(mx, v[i]);
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}