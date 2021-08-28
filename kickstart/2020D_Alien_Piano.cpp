#include<bits/stdc++.h>
#define maxn 10050
using namespace std;
int T, n, p[maxn], dp[maxn][4];
void reset(int n) {
    for (int i=2;i<=n;i++)
        for (int j=0;j<4;j++)
            dp[i][j] = 1e9+7;
}
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        scanf("%d", &n);
        reset(n);
        for (int i=1;i<=n;i++) scanf("%d", &p[i]);
        for (int i=2;i<=n;i++) {
            if (p[i] == p[i-1]) {
                for (int j=0;j<4;j++)
                    for (int k=0;k<4;k++)
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + (j != k));
            }
            else if (p[i] > p[i-1]) {
                for (int j=0;j<4;j++)
                    for (int k=0;k<4;k++)
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + (j <= k));
            }
            else {
                for (int j=0;j<4;j++)
                    for (int k=0;k<4;k++)
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + (j >= k));
            }
        }
        int mn = 1e9+7;
        for (int i=0;i<4;i++) mn = min(mn, dp[n][i]);
        printf("Case #%d: %d\n", t, mn);
    }
    return 0;
}