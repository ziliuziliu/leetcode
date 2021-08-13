#include<bits/stdc++.h>
#define maxn 1050
using namespace std;
int T, n;
long long d, x[maxn];
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        scanf("%d%lld", &n, &d);
        for (int i=1;i<=n;i++) scanf("%lld", &x[i]);
        for (int i=n;i>=1;i--) d = d / x[i] * x[i];
        printf("Case #%d: %lld\n", t, d);
    }
    return 0;
}