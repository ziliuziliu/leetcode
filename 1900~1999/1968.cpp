#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            ans.push_back(nums[l]);
            ans.push_back(nums[r]);
            l++; r--;
        }
        if (l == r) ans.push_back(nums[l]);
        return ans;
    }
};
int main() {
    int x; vector<int> nums;
    for (int i=0;i<5;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    s.rearrangeArray(nums);
    return 0;
}