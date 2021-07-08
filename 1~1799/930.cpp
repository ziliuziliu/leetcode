#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, ans = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int i=0;i<nums.size();i++) {
            sum += nums[i];
            if (mp.count(sum-goal)) ans += mp[sum-goal];
            if (!mp.count(sum)) mp[sum] = 0;
            mp[sum]++;
        }
        return ans;
    }
};
int main() {
    int x, goal;
    vector<int> nums;
    for (int i=0;i<5;i++) {
        cin >> x;
        nums.push_back(x);
    }
    cin >> x;
    Solution s;
    cout << s.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}