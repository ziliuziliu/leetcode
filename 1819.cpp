#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int cnt[200050], mx = 0, ans = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i=0;i<nums.size();i++) {
            mx = max(mx, nums[i]);
            cnt[nums[i]]++;
        } 
        for (int k=1;k<=mx;k++)
            for (int i=2*k;i<=mx;i+=k)
                cnt[k] += cnt[i];
        for (int k=1;k<=mx;k++) {
            if (!cnt[k]) continue;
            bool sameCnt = false;
            for (int i=2*k;i<=mx;i+=k) {
                if (cnt[i] == cnt[k]) {
                    sameCnt = true;
                    break;
                }
            }
            if (!sameCnt) ans++;
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums;
    int x;
    for (int i=0;i<5;i++) {
        cin >> x;
        nums.push_back(x);
    }
    cout << s.countDifferentSubsequenceGCDs(nums) << endl;
    return 0;
}