#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long w = 0;
        int l = 0, ans = 1, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=1;i<n;i++) {
            w += (long long)(i - l) * (nums[i] - nums[i-1]);
            while (l < i && w > k) w -= nums[i] - nums[l++];
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
int main() {
    vector<int> nums;
    int k;
    for (int i=0;i<3;i++) {
        cin >> k;
        nums.push_back(k);
    }
    cin >> k;
    Solution s;
    cout << s.maxFrequency(nums, k) << endl;
    return 0;
}