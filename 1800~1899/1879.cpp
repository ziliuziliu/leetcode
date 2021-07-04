#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int dp[20000], n = nums1.size();
        int inf = 1e9+7;
        for (int s=0;s<(1<<n);s++) dp[s] = inf;
        dp[0] = 0;
        for (int s=0;s<(1<<n);s++) {
            int cnt = __builtin_popcount(s);
            for (int i=0;i<n;i++) {
                if (s&(1<<i)) continue;
                dp[s|(1<<i)] = min(dp[s|(1<<i)], dp[s] + (nums1[i]^nums2[cnt]));
            }
        }
        return dp[(1<<n)-1];
    }
};
int main() {
    vector<int> nums1, nums2;
    int x;
    for (int i=0;i<3;i++) {
        cin >> x;
        nums1.push_back(x);
    }
    for (int i=0;i<3;i++) {
        cin >> x;
        nums2.push_back(x);
    }
    Solution s;
    cout << s.minimumXORSum(nums1, nums2) << endl;
    return 0;
}