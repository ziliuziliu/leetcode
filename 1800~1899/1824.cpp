#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:

    int dp[500050][4], inf = 1e9+7;

    int minSideJumps(vector<int>& obstacles) {
        dp[0][2] = 0; dp[0][1] = dp[0][3] = 1;
        int n = obstacles.size()-1;
        for (int i=1;i<=n;i++) {
            dp[i][1] = dp[i][2] = dp[i][3] = inf;
            if (obstacles[i] != 1) {
                if (obstacles[i-1] != 1)  dp[i][1] = min(dp[i][1], dp[i-1][1]);
                if (obstacles[i-1] != 2 && (obstacles[i-1] != 1 || obstacles[i] != 2)) dp[i][1] = min(dp[i][1], dp[i-1][2] + 1);
                if (obstacles[i-1] != 3 && (obstacles[i-1] != 1 || obstacles[i] != 3)) dp[i][1] = min(dp[i][1], dp[i-1][3] + 1);
            }
            if (obstacles[i] != 2) {
                if (obstacles[i-1] != 2)  dp[i][2] = min(dp[i][2], dp[i-1][2]);
                if (obstacles[i-1] != 1 && (obstacles[i-1] != 2 || obstacles[i] != 1)) dp[i][2] = min(dp[i][2], dp[i-1][1] + 1);
                if (obstacles[i-1] != 3 && (obstacles[i-1] != 2 || obstacles[i] != 3)) dp[i][2] = min(dp[i][2], dp[i-1][3] + 1);
            }
            if (obstacles[i] != 3) {
                if (obstacles[i-1] != 3)  dp[i][3] = min(dp[i][3], dp[i-1][3]);
                if (obstacles[i-1] != 1 && (obstacles[i-1] != 3 || obstacles[i] != 1)) dp[i][3] = min(dp[i][3], dp[i-1][1] + 1);
                if (obstacles[i-1] != 2 && (obstacles[i-1] != 3 || obstacles[i] != 2)) dp[i][3] = min(dp[i][3], dp[i-1][2] + 1);
            }
        }
        int ans = min(dp[n][1], dp[n][2]); ans = min(ans, dp[n][3]);
        return ans;
    }
};
int main() {
    int x;
    vector<int> obstacles;
    for (int i=0;i<5;i++) {
        cin >> x;
        obstacles.push_back(x);
    }
    Solution s;
    cout << s.minSideJumps(obstacles) << endl;
    return 0;
}