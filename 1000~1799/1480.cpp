#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i=1;i<nums.size();i++) nums[i] += nums[i-1];
        return nums;
    }
};
int main() {
    int x; vector<int> nums;
    for (int i=0;i<4;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s; s.runningSum(nums);
    return 0;
}