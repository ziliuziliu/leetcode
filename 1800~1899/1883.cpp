#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        double eps = 1e-8;
        double dp[105][105];
        int n = dist.size();
        if (n == 1) 
            return (double)dist[0] / speed - eps <= hoursBefore ? 0 : -1;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                dp[i][j] = 1e9;
        dp[0][0] = ceil((double)dist[0] / speed - eps);
        dp[0][1] = (double)dist[0] / speed;
        for (int i=1;i<n-1;i++) {
            dp[i][0] = ceil(dp[i-1][0] + (double)dist[i] / speed - eps);
            for (int j=1;j<=i+1;j++)
                dp[i][j] = min(ceil(dp[i-1][j] + (double)dist[i] / speed - eps), dp[i-1][j-1] + (double)dist[i] / speed);
        }
        for (int i=0;i<n;i++) dp[n-1][i] = dp[n-2][i] + (double)dist[n-1] / speed;
        dp[n-1][n] = dp[n-1][n-1];
        int ans = -1;
        for (int i=0;i<=n;i++) {
            if (dp[n-1][i] - eps <= hoursBefore) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> dist;
    int speed, hoursBefore, x;
    for (int i=0;i<2;i++) {
        cin >> x;
        dist.push_back(x);
    }
    cin >> speed;
    cin >> hoursBefore;
    Solution s;
    cout << s.minSkips(dist, speed, hoursBefore) << endl;
    return 0;
}