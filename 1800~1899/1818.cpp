#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> s; int mod = 1e9+7; s.insert(mod); s.insert(-mod);
        int n = nums1.size(); int ans = 0, diff = 0;
        for (int i=0;i<n;i++) s.insert(nums1[i]);
        for (int i=0;i<n;i++) ans = (ans + abs(nums1[i] - nums2[i])) % mod;
        for (int i=0;i<n;i++) {
            int ret = abs(nums1[i] - nums2[i]);
            set<int>::iterator it = s.lower_bound(nums2[i]);
            if (*it != mod) diff = max(diff, ret - (*it - nums2[i]));
            it = prev(it);
            if (*it != -mod) diff = max(diff, ret - (nums2[i] - *it));
        }
        ans = (ans - diff + mod) % mod;
        return ans;
    }
};
int main() {
    vector<int> nums1, nums2;
    int x;
    for (int i=0;i<3;i++) {
        cin >> x;
        nums1.push_back(x);
    }
    for (int i=0;i<3;i++) {
        cin >> x;
        nums2.push_back(x);
    }
    Solution s;
    cout << s.minAbsoluteSumDiff(nums1, nums2) << endl;
    return 0;
}