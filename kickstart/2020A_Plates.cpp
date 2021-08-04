#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[55][1550] = {0};
int T, n, m, p, a[55][35];
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d%d", &n, &m, &p);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d", &a[i][j]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=min(p, i*m);j++) {
                int ret = 0; dp[i][j] = dp[i-1][j];
                for (int k=1;k<=min(m, j);k++) {
                    ret += a[i][k];
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k] + ret);
                }
            }
        printf("Case #%d: %d\n", t, dp[n][p]);
    }
    return 0;
}