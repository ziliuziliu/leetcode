#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int nums[105] = {0}, mx = 0; nums[0] = 0; nums[1] = 1;
        for (int i=2;i<=n;i++) {
            if (i&1) nums[i] = nums[i>>1] + nums[(i>>1)+1];
            else nums[i] = nums[i>>1];
            mx = max(mx, nums[i]);
        }
        return mx;
    }
};
int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.getMaximumGenerated(n) << endl;
    return 0;
}