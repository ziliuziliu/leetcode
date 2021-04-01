#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0;
        for (int i=0;i<nums.size();i++)
            sum += nums[i];
        return ceil((double)abs(sum-goal) / limit);
    }
};
int main() {
    int x, y, z;
    vector<int> nums;
    for (int i=0;i<4;i++) {
        cin >> x;
        nums.push_back(x);
    }
    cin >> y >> z;
    Solution s;
    cout << s.minElements(nums, y, z) << endl;
    return 0;
}