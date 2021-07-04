#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int mod = 1000000007;
        int cnt[100050], sum[100050], size = nums.size(), mx = 0;
        for (int i=0;i<size;i++) {
            cnt[nums[i]]++;
            mx = max(mx, nums[i]);
        }
        int ans = 0;
        for (int i=1;i<=mx;i++) sum[i] = sum[i-1] + cnt[i];
        for (int i=1;i<=mx;i++)
            for (int j=1;i*j<=mx;j++) {
                long long ret = sum[min(i*(j+1)-1, mx)] - sum[i*j - 1];
                ret = (ret*j) % mod;
                ret = (ret*cnt[i]) % mod;
                ans = (ans + ret) % mod;
            }
        return ans;
    }
};
int main() {
    vector<int> nums;
    int n;
    for (int i=0;i<7;i++) {
        cin >> n;
        nums.push_back(n);
    }
    Solution s;
    cout << s.sumOfFlooredPairs(nums) << endl;
    return 0;
}