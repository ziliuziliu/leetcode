#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        vector<int> sum[101];
        for (int i=1;i<=100;i++) sum[i].push_back(0);
        for (int i=0;i<nums.size();i++)
            for (int j=1;j<=100;j++) {
                int top = sum[j][sum[j].size()-1];
                sum[j].push_back(top+(j==nums[i]));
            }
        for (int i=0;i<queries.size();i++) {
            int l = queries[i][0], r = queries[i][1];
            int ret = -1, s, ans = 1e9;
            for (int j=1;j<=100;j++) {
                s = sum[j][r+1]-sum[j][l];
                if (s != 0) {
                    if (ret != -1) ans = min(ans, j-ret);
                    ret = j;
                }
            }
            if (ans != 1e9) result.push_back(ans);
            else result.push_back(-1);
        }
        return result;
    }
};
int main() {
    vector<int> nums;
    vector<vector<int>> queries;
    int x;
    for (int i=0;i<4;i++) {
        cin >> x;
        nums.push_back(x);
    }
    for (int i=0;i<4;i++) {
        queries.push_back(vector<int>());
        for (int j=0;j<2;j++) {
            cin >> x;
            queries[i].push_back(x);
        }
    }
    Solution s;
    s.minDifference(nums, queries);
    return 0;
}