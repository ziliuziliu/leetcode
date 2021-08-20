#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int father[20050];
    bool mp[20050] = {false};
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
    
    int cal(int x, int y, int row, int col) {
        return (x - 1) * col + y;
    }
    
    bool available(int x, int y, int row, int col) { return x >= 1 && x <= row && y >= 1 && y <= col; }
    
    int getfather(int x) {
        if (x != father[x]) father[x] = getfather(father[x]);
        return father[x];
    }
    
    void merge(int s1, int s2) {
        int f1 = getfather(s1), f2 = getfather(s2);
        if (f1 != f2) father[f1] = f2;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int start = row * col + 1, end = row * col + 2, ans = -1;
        for (int i=1;i<=row*col+2;i++) father[i] = i;
        for (int i=1;i<=col;i++) merge(cal(1, i, row, col), start);
        for (int i=1;i<=col;i++) merge(cal(row, i, row, col), end);
        for (int i=cells.size()-1;i>=0;i--) {
            int x = cells[i][0], y = cells[i][1];
            mp[cal(x, y, row, col)] = true;
            for (int j=0;j<4;j++) {
                int tx = x + dx[j], ty = y + dy[j];
                if (available(tx, ty, row, col) && mp[cal(tx, ty, row, col)])
                    merge(cal(x, y, row, col), cal(tx, ty, row, col));
            }        
            if (getfather(start) == getfather(end)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
int main() {
    int row, col, x;
    vector<vector<int>> cells;
    cin >> row >> col;
    for (int i=0;i<4;i++) {
        cells.push_back(vector<int>());
        for (int j=0;j<2;j++) {
            cin >> x;
            cells[i].push_back(x);
        }
    }
    Solution s;
    cout << s.latestDayToCross(row, col, cells) << endl;
    return 0;
}