#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool check_na(int s, int top) {
        int bit[6];
        for (int i=0;i<top;i++) {
            bit[i] = s%3;
            s /= 3;
        }
        for (int i=0;i<top-1;i++) {
            if (bit[i] == bit[i+1])
                return false;
        }
        return true;
    }
    
    bool check_available(int s1, int s2, int top) {
        int bit1[6];
        for (int i=0;i<top;i++) {
            bit1[i] = s1%3;
            s1 /= 3;
        }
        int bit2[6];
        for (int i=0;i<top;i++) {
            bit2[i] = s2%3;
            s2 /= 3;
        }
        for (int i=0;i<top;i++) {
            if (bit1[i] == bit2[i])
                return false;
        }
        return true;
    }
    
    int colorTheGrid(int m, int n) {
        int mod = 1e9+7, top = 1;
        for (int i=0;i<m;i++) top *= 3;
        int dp[1050][300]; memset(dp, 0, sizeof(dp));
        bool na_state[300]; memset(na_state, 0, sizeof(na_state));
        for (int s=0;s<top;s++) na_state[s] = check_na(s, m);
        for (int s=0;s<top;s++)
            if (na_state[s]) dp[0][s] = 1;
        for (int i=1;i<n;i++)
            for (int j=0;j<top;j++) {
                if (na_state[j]) {
                    for (int k=0;k<top;k++) {
                        if (na_state[k] && check_available(j, k, m))
                            dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
                    }
                }
            }
        int ans = 0;
        for (int i=0;i<top;i++)
            ans = (ans + dp[n-1][i]) % mod;
        return ans;
    }
};
int main() {
    int m, n;
    cin >> m >> n;
    Solution s;
    cout << s.colorTheGrid(m, n) << endl;
    return 0;
}