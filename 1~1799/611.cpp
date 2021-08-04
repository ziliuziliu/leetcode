#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, pos = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] != 0) break;
            pos = i+1;
        }
        if (pos == nums.size()) return 0;
        for (int i=pos;i<nums.size();i++) {
            int k = i + 1;
            for (int j=i+1;j<nums.size();j++) {
                while (k < nums.size() && nums[i] + nums[j] > nums[k]) k++;
                ans += k - j - 1;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums; int x;
    for (int i=0;i<4;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    cout << s.triangleNumber(nums) << endl;
    return 0;
}