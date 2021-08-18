#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:

    int pow[15];

    int update(int s, int pos) {
        int ss = s;
        for (int i=0;i<pos;i++) s /= 3;
        int bit = s%3;
        if (bit == 2) return -1;
        else return ss+pow[pos];
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        pow[0] = 1; for (int i=1;i<=11;i++) pow[i] = pow[i-1]*3;
        int n = baseCosts.size(), m = toppingCosts.size();
        int dp[100000], ans = -1;
        for (int t=0;t<n;t++) {
            memset(dp, 0, sizeof(dp));
            dp[0] = baseCosts[t];
            for (int s=0;s<pow[m];s++)
                for (int i=0;i<m;i++) {
                    int s1 = update(s, i);
                    if (s1 != -1)
                        dp[s1] = dp[s] + toppingCosts[i];
                }
            for (int s=0;s<pow[m];s++) {
                if (ans == -1) ans = dp[s];
                else if (abs(ans-target) > abs(dp[s]-target)) ans = dp[s];
                else if ((abs(ans-target) == abs(dp[s]-target)) && (dp[s] < ans)) ans = dp[s];
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    int x, y, target;
    vector<int> baseCosts, toppingCosts;
    for (int i=0;i<2;i++) {
        cin >> x;
        baseCosts.push_back(x);
    }
    for (int i=0;i<2;i++) {
        cin >> y;
        toppingCosts.push_back(y);
    }
    cin >> target;
    cout << s.closestCost(baseCosts, toppingCosts, target) << endl;
    return 0;
}