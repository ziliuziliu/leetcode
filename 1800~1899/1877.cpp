#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mx = 0;
        for (int i=0;i<n/2;i++) mx = max(mx, nums[i] + nums[n-1-i]);
        return mx;
    }
};
int main() {
    vector<int> nums;
    int x;
    for (int i=0;i<4;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    cout << s.minPairSum(nums) << endl;
    return 0;
}