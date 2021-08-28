#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a%b);
    }
    
    int findGCD(vector<int>& nums) {
        int mn = 1050, mx = 0;
        for (int i=0;i<nums.size();i++) { mn = min(mn, nums[i]); mx = max(mx, nums[i]); }
        return gcd(mn, mx);
    }
};
int main() {
    int x; vector<int> nums;
    for (int i=0;i<5;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    cout << s.findGCD(nums) << endl;
    return 0;
}