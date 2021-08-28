#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        if (m == 1) {
            int sum = 0;
            for (int i=0;i<n;i++) sum += mat[i][0];
            return abs(sum - target);
        }
        bool vis[75][1050] = {false};
        vis[0][0] = true;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int k=mat[i-1][j-1];k<=1000;k++) 
                    vis[i][k] |= vis[i-1][k-mat[i-1][j-1]];
        int ans1 = -1, ans2 = -1;
        for (int i=target;i<=1000;i++) {
            if (vis[n][i]) { ans1 = i; break; }
        }
        for (int i=target;i>=0;i--) {
            if (vis[n][i]) { ans2 = i; break; }
        }
        if (ans1 == -1) return target - ans2;
        if (ans2 == -1) return ans1 - target;
        return min(ans1 - target, target - ans2);
    }
};
int main() {
    int x, target; vector<vector<int>> mat;
    for (int i=0;i<3;i++) {
        mat.push_back(vector<int>());
        for (int j=0;j<3;j++) {
            cin >> x;
            mat[i].push_back(x);
        }
    }
    Solution s; cout << s.minimizeTheDifference(mat, target) << endl;
    return 0;
}