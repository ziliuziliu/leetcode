#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        long long cnt[100050], sum[100050], mx = 0, ans = 1e12, mxp = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        for (int i=0;i<packages.size();i++) {
            cnt[packages[i]]++;
            mx = max(mx, (long long)packages[i]);
        }
        mxp = mx;
        for (int i=0;i<boxes.size();i++)
            for (int j=0;j<boxes[i].size();j++)
                mx = max(mx, (long long)boxes[i][j]);
        for (int i=1;i<=mx;i++) sum[i] = sum[i-1] + cnt[i]*i;
        for (int i=1;i<=mx;i++) cnt[i] += cnt[i-1];
        for (int i=0;i<boxes.size();i++) {
            sort(boxes[i].begin(), boxes[i].end());
            int top = boxes[i].size();
            if (boxes[i][top-1] < mxp) continue;
            long long ret = boxes[i][0] * cnt[boxes[i][0]] - sum[boxes[i][0]];
            for (int j=1;j<top;j++)
                ret += boxes[i][j] * (cnt[boxes[i][j]] - cnt[boxes[i][j-1]]) - (sum[boxes[i][j]] - sum[boxes[i][j-1]]);
            ans = min(ans, ret);
        }
        if (ans == 1e12) return -1;
        return ans%1000000007;
    }
};
int main() {
    vector<int> packages;
    vector<vector<int>> boxes;
    int x;
    for (int i=0;i<3;i++) {
        cin >> x;
        packages.push_back(x);
    }
    for (int i=0;i<3;i++) {
        boxes.push_back(vector<int>());
        for (int j=0;j<2;j++) {
            cin >> x;
            boxes[i].push_back(x);
        }
    }
    Solution s;
    cout << s.minWastedSpace(packages, boxes) << endl;
    return 0;
}