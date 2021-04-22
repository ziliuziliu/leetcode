#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int sum[105][105], ans = -1000000007;
        memset(sum, 0, sizeof(sum));
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        set<int> s;
        set<int>::iterator it;
        for (int i=1;i<=m;i++)
            for (int j=1;j<=i;j++) {
                s.clear();
                s.insert(0);
                for (int l=1;l<=n;l++) {
                    int currentSum = sum[i][l]-sum[j-1][l];
                    it = s.lower_bound(currentSum-k);
                    if (it != s.end())
                        ans = max(ans, currentSum - *it);
                    s.insert(currentSum);
                }
            }
        return ans;
    }
};
int main() {
    vector<vector<int>> matrix;
    int x;
    for (int i=0;i<1;i++) {
        matrix.push_back(vector<int>());
        for (int j=0;j<3;j++) {
            cin >> x;
            matrix[i].push_back(x);
        }
    }
    int k;
    cin >> k;
    Solution s;
    cout << s.maxSumSubmatrix(matrix, k) << endl;
    return 0;
}