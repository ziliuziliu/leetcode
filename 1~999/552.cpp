#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) return 3;
        int dp[100050][3][2] = {0}, mod = 1e9+7, ans = 0;
        dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
        for (int i=2;i<=n;i++) {
            for (int j=0;j<2;j++) {
                dp[i][0][j] = ((dp[i-1][0][j] + dp[i-1][1][j]) % mod + dp[i-1][2][j]) % mod;
                dp[i][1][j] = dp[i-1][0][j];
                dp[i][2][j] = dp[i-1][1][j];
            }
            dp[i][0][1] = (((dp[i][0][1] + dp[i-1][0][0]) % mod + dp[i-1][1][0]) % mod + dp[i-1][2][0]) % mod;
        }
        for (int i=0;i<3;i++)
            for (int j=0;j<2;j++)
                ans = (ans + dp[n][i][j]) % mod;
        return ans;
    }
};
int main() {
    int n; Solution s;
    cin >> n;
    cout << s.checkRecord(n) << endl;
    return 0;
}