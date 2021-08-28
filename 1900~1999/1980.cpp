#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        bool vis[70000] = {false};
        for (int i=0;i<nums.size();i++) {
            int ret = 0;
            for (int j=0;j<nums[i].length();j++)
                ret = (ret << 1) + (nums[i][j] == '1');
            vis[ret] = true;
        }
        int n = nums[0].length();
        string ans; int bits[17] = {0}, cnt = 0;
        for (int i=0;i<(1<<n);i++) {
            if (!vis[i]) {
                int num = i;
                while (num) { bits[cnt++] = num % 2; num >>= 1; }
                break;
            }
        }
        for (int i=n-1;i>=0;i--) ans.append(1, '0' + bits[i]);
        return ans;
    }
};
int main() {
    string x; vector<string> nums;
    for (int i=0;i<2;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s; cout << s.findDifferentBinaryString(nums) << endl;
    return 0;
}