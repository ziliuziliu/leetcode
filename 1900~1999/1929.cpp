#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i=0;i<n;i++) ans.push_back(nums[i]);
        for (int i=0;i<n;i++) ans.push_back(nums[i]);
        return ans;
    }
};
int main() {
    vector<int> nums;
    int x;
    for (int i=0;i<3;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    s.getConcatenation(nums);
    return 0;
}