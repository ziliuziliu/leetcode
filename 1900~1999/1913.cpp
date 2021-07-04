#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-1] * nums[n-2] - nums[0] * nums[1];
    }
};
int main() {
    vector<int> nums;
    int x;
    for (int i=0;i<5;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    cout << s.maxProductDifference(nums) << endl;
    return 0;
}