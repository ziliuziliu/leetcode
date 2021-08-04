#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int dp[100050][3] = {0}, mod = 1e9+7, n = nums.size();
        if (nums[0] == 0) dp[0][0] = 1;
        for (int i=1;i<n;i++) {
            dp[i][0] = dp[i-1][0];
            if (nums[i] == 0) 
                dp[i][0] = (dp[i][0] + dp[i-1][0] + 1) % mod;
            dp[i][1] = dp[i-1][1];
            if (nums[i] == 1)
                dp[i][1] = ((dp[i][1] + dp[i-1][1]) % mod + dp[i-1][0]) % mod;
            dp[i][2] = dp[i-1][2];
            if (nums[i] == 2) 
                dp[i][2] = ((dp[i][2] + dp[i-1][2]) % mod + dp[i-1][1]) % mod;
        }
        return dp[n-1][2];
    }
};
int main() {
    int x;
    vector<int> nums;
    for (int i=0;i<4;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    cout << s.countSpecialSubsequences(nums) << endl;
    return 0;
}