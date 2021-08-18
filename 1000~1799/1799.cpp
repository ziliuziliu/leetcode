#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a%b) : a;
    }
    int bitcount(int x) {
        int cnt = 0;
        while (x) {
            cnt += (x&1);
            x >>= 1;
        }
        return cnt;
    }
    int maxScore(vector<int>& nums) {
        int dp[100050] = {0}, n = nums.size();
        for (int s=0;s<(1<<n);s++) {
            int cnt = bitcount(s);
            if (cnt&1) continue;
            cnt >>= 1;
            for (int i=0;i<n;i++) {
                if (s & (1<<i)) {
                    for (int j=i+1;j<n;j++) {
                        if (s & (1<<j))
                            dp[s] = max(dp[s], dp[s^(1<<i)^(1<<j)] + cnt*gcd(nums[i], nums[j]));
                    }
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
int main() {
    int x;
    vector<int> nums;
    for (int i=0;i<2;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    cout << s.maxScore(nums) << endl;
    return 0;
}