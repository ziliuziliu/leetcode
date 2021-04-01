#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    struct group {
        map<int, int> mp;
        int size, id;
        int mode, cnt;
    } g[2020];
    int dp[2][1050];

    static bool cmp1(const group &g1, const group &g2) {return g1.cnt < g2.cnt;}
    static bool cmp2(const group &g1, const group &g2) {return g1.id < g2.id;}

    void init_groups(vector<int>& nums, int k) {
        for (int i=0;i<k;i++) {
            int size = 0, mode = -1, cnt = 0;
            for (int j=i;j<nums.size();j+=k) {
                if (!g[i].mp.count(nums[j])) g[i].mp[nums[j]] = 1;
                else g[i].mp[nums[j]]++;
                size++;
                if (g[i].mp[nums[j]] > cnt) {
                    cnt = g[i].mp[nums[j]];
                    mode = nums[j];
                }
            }
            g[i].size = size, g[i].mode = mode, g[i].cnt = cnt, g[i].id = i;
        }
    }

    int f1(int k) {
        sort(g, g+k, cmp1);
        int ans = 0, xorsum = 0;
        for (int i=1;i<k;i++) {
            ans += g[i].size - g[i].cnt;
            xorsum ^= g[i].mode;
        }
        ans += (xorsum == g[0].mode) ? (g[0].size - g[0].cnt) : g[0].size;
        sort(g, g+k, cmp2);
        return ans;
    }
    
    int f2(int k) {
        for (int i=0;i<k;i++) {
            for (int j=0;j<1024;j++)
                dp[i&1][j] = 1000000007;
            if (i == 0) {
                for (map<int, int>::iterator it = g[i].mp.begin(); it != g[i].mp.end(); it++)
                    dp[i&1][it->first] = g[i].size - it->second;
            }
            else {
                for (int j=0;j<1024;j++)
                    for (map<int, int>::iterator it = g[i].mp.begin(); it != g[i].mp.end(); it++)
                        dp[i&1][j] = min(dp[i&1][j], dp[(i&1)^1][j^(it->first)] + g[i].size - it->second);
            }
        }
        return dp[k-1&1][0];
    }

    int minChanges(vector<int>& nums, int k) {
        init_groups(nums, k);
        return min(f1(k), f2(k));
    }
};
int main() {
    Solution s;
    vector<int> nums;
    int k;
    for (int i=0;i<15;i++) {
        cin >> k;
        nums.push_back(k);
    }
    cin >> k;
    cout << s.minChanges(nums, k) << endl;
    return 0;
}