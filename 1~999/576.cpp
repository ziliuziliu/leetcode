#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int dp[55][55][55] = {0}, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int mod = 1e9+7, ans = 0;

    bool boundary(int x, int y, int m, int n) { return x == 0 || x == m+1 || y == 0 || y == n+1; }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        startRow++; startColumn++; dp[startRow][startColumn][0] = 1;
        for (int t=0;t<maxMove;t++)
            for (int i=1;i<=m;i++)
                for (int j=1;j<=n;j++)
                    for (int k=0;k<4;k++) {
                        int x = i + dx[k], y = j + dy[k];
                        dp[x][y][t+1] = (dp[x][y][t+1] + dp[i][j][t]) % mod;
                        if (boundary(x, y, m, n)) ans = (ans + dp[x][y][t+1]) % mod;
                    }
        return ans;
    }
};
int main() {
    int m, n, maxMove, startRow, startColumn;
    cin >> m >> n >> maxMove >> startRow >> startColumn;
    Solution s;
    cout << s.findPaths(m, n, maxMove, startRow, startColumn) << endl;
    return 0;
}