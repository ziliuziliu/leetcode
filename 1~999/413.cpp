#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), ans = 0;
        for (int i=0;i<n-1;i++) nums[i] = nums[i+1] - nums[i];
        while (l < n-1) {
            while (r < n-1 && nums[r] == nums[l]) r++;
            ans += (r-l) * (r-l-1) / 2;
            l = r;
        }
        return ans;
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
    cout << s.numberOfArithmeticSlices(nums) << endl;
    return 0;
}