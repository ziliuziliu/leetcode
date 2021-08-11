#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct event {
        int i, j;
        long long d;
        event(int i, int j, long long d):i(i),j(j),d(d) {}
        bool operator < (const event &e) {
            if (this->d != e.d) return this->d < e.d;
            if (this->j != e.j) return this->j < e.j;
            return this->i < e.i;
        }
    };

    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<event> v;
        set<int> s;
        int dp[1050] = {0};
        for (int i=0;i<nums.size();i++)
            for (int j=i+1;j<nums.size();j++)
                v.push_back(event(i, j, (long long)nums[j] - nums[i]));
        sort(v.begin(), v.end());
        int l = 0, r = 0, ans = 0;
        while (l < v.size()) {
            while (r < v.size() && v[r].d == v[l].d) {
                s.insert(v[r].i); s.insert(v[r].j);
                dp[v[r].i] = dp[v[r].j] = 1;
                r++;
            }
            for (int i=l;i<r;i++) dp[v[i].j] += dp[v[i].i];
            ans -= r - l;
            for (set<int>::iterator it = s.begin(); it != s.end(); it++) ans += dp[*it] - 1;
            s.clear(); l = r;
        }
        return ans;
    }
};
int main() {
    int x;
    vector<int> nums;
    for (int i=0;i<5;i++) {
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    cout << s.numberOfArithmeticSlices(nums) << endl;
    return 0;
}