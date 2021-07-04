#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:

    long long reverse(int x) {
        long long ans = 0;
        while (x) {
            ans = ans*10 + x%10;
            x /= 10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        map<long long, int> cnt;
        int ans = 0;
        for (int i=0;i<nums.size();i++) {
            long long dif = reverse(nums[i]) - nums[i];
            if (cnt.count(dif) == 0) cnt[dif] = 0;
            ans = (ans + cnt[dif]) % 1000000007;
            cnt[dif]++;
        }
        return ans;
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
    cout << s.countNicePairs(nums) << endl;
    return 0;
}