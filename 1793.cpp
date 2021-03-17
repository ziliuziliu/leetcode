#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k, right = k;
        int ans = nums[k], mn = nums[k];
        while (true) {
            while (left>0 && nums[left-1]>mn) left--;
            while (right<nums.size()-1 && nums[right+1]>mn) right++;
            ans = max(ans, (right-left+1)*mn);
            if (right-left+1 == nums.size()) break;
            if (left == 0) mn = nums[++right];
            else if (right == nums.size()-1) mn = nums[--left];
            else {
                if (nums[left-1] > nums[right+1]) mn = nums[--left];
                else mn = nums[++right];
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums;
    int k;
    for (int i=0;i<8;i++) {
        cin >> k;
        nums.push_back(k);
    }
    cin >> k;
    Solution s;
    cout << s.maximumScore(nums, k) << endl;
    return 0;
}