#include<iostream>
#include<cstdio>
using namespace std;
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        int mod = 1000000007;
        long long dp[1050][1050];
        if (n == 1) return (k == 1);
        dp[1][1] = 1;
        for (int i=2;i<=n;i++)
            for (int j=1;j<=k;j++) {
                long long inter = (long long)(i-1) * dp[i-1][j] % mod;
                dp[i][j] = (dp[i-1][j-1] + inter) % mod;
            }
        return dp[n][k];
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    Solution s;
    cout << s.rearrangeSticks(n, k) << endl;
    return 0;
}