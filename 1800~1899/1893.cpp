#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int cnt[100] = {0};
        for (int i=0;i<ranges.size();i++) {
            cnt[ranges[i][0]]++;
            cnt[ranges[i][1]+1]--;
        }
        for (int i=1;i<left;i++) cnt[i] += cnt[i-1];
        for (int i=left;i<=right;i++) {
            cnt[i] += cnt[i-1];
            if (cnt[i] == 0) return false;
        }
        return true;
    }
};
int main() {
    vector<vector<int>> ranges;
    int left, right, x;
    for (int i=0;i<3;i++) {
        ranges.push_back(vector<int>());
        for (int j=0;j<2;j++) {
            cin >> x;
            ranges[i].push_back(x);
        }
    }
    cin >> left >> right;
    Solution s;
    cout << s.isCovered(ranges, left, right) << endl;
    return 0;
}