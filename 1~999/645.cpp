#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int cnt[10050], n = nums.size();
        memset(cnt, 0, sizeof(cnt));
        for (int i=0;i<nums.size();i++) cnt[nums[i]]++;
        int ans1, ans2;
        for (int i=1;i<=n;i++) {
            if (cnt[i] == 0) ans1 = i;
            else if (cnt[i] == 2) ans2 = i;
        }
        vector<int> ans; ans.push_back(ans2); ans.push_back(ans1);
        return ans;
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
    s.findErrorNums(nums);
    return 0;
}