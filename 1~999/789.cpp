#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getdis(int x1, int y1, int x2, int y2) { return abs(x2 - x1) + abs(y2 - y1); }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int mn = abs(target[0]) + abs(target[1]);
        for (int i=0;i<ghosts.size();i++) {
            if (getdis(ghosts[i][0], ghosts[i][1], target[0], target[1]) <= mn)
                return false;
        }
        return true;
    }
};
int main() {
    vector<vector<int>> ghosts; vector<int> target;
    int x;
    for (int i=0;i<2;i++) {
        ghosts.push_back(vector<int>());
        for (int j=0;j<2;j++) {
            cin >> x;
            ghosts[i].push_back(x);
        }
    }
    for (int i=0;i<2;i++) {
        cin >> x;
        target.push_back(x);
    }
    Solution s;
    cout << s.escapeGhosts(ghosts, target) << endl;
    return 0;
}