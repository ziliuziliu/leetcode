#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int layer = min(n/2, m/2);
        vector<vector<int>> ans;
        for (int i=0;i<n;i++) {
            ans.push_back(vector<int>());
            for (int j=0;j<m;j++)
                ans[i].push_back(0);
        }
        for (int l=0;l<layer;l++) {
            vector<int> c;
            for (int i=l;i<=n-1-l;i++) {c.push_back(i); c.push_back(l);}
            for (int j=l+1;j<=m-l-2;j++) {c.push_back(n-l-1); c.push_back(j);}
            for (int i=n-l-1;i>=l;i--) {c.push_back(i); c.push_back(m-l-1);}
            for (int j=m-l-2;j>=l+1;j--) {c.push_back(l); c.push_back(j);}
            int round = k%(2*n+2*m-8*l-4), c_len = c.size();
            int pos = 2*round;
            for (int i=0;i<c_len;i+=2) {
                ans[c[pos]][c[pos+1]] = grid[c[i]][c[i+1]];
                pos = (pos+2)%c_len;
            }
        }
        return ans;
    }
};
int main() {
    int x, k;
    vector<vector<int>> grid;
    for (int i=0;i<2;i++) {
        grid.push_back(vector<int>());
        for (int j=0;j<2;j++) {
            cin >> x;
            grid[i].push_back(x);
        }
    }
    cin >> k;
    Solution s;
    s.rotateGrid(grid, k);
    return 0;
}