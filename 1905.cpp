#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
class Solution {
public:
    
    int label[505][505], label2[505][505];
    int cnt = 0;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    
    bool available(int i, int j, int n, int m) {
        return i>=0 && i<n && j>=0 && j<m;
    }
    
    void bfs(vector<vector<int>>& grid, int startX, int startY) {
        int n = grid.size(), m = grid[0].size();
        cnt++;
        queue<int> q; q.push(startX); q.push(startY);
        label[startX][startY] = cnt;
        while (!q.empty()) {
            int topX = q.front(); q.pop();
            int topY = q.front(); q.pop();
            for (int i=0;i<4;i++) {
                int X = topX + dx[i], Y = topY + dy[i];
                if (available(X, Y, n, m)) {
                    if (grid[X][Y] == 1 && label[X][Y] == 0) {
                        label[X][Y] = cnt;
                        q.push(X); q.push(Y);
                    }
                }
            }
        }
    }
    
    bool bfs2(vector<vector<int>>& grid, int startX, int startY) {
        int n = grid.size(), m = grid[0].size();
        bool flag = true;
        queue<int> q; q.push(startX); q.push(startY);
        int island = -1;
        label2[startX][startY] = 1;
        while (!q.empty()) {
            int topX = q.front(); q.pop();
            int topY = q.front(); q.pop();
            if (label[topX][topY] == 0) flag = false;
            else {
                if (island != -1 && island != label[topX][topY]) flag = false;
                island = label[topX][topY];
            }
            for (int i=0;i<4;i++) {
                int X = topX + dx[i], Y = topY + dy[i];
                if (available(X, Y, n, m)) {
                    if (grid[X][Y] == 1 && label2[X][Y] == 0) {
                        label2[X][Y] = 1;
                        q.push(X); q.push(Y);
                    }
                }
            }
        }
        return flag;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        memset(label, 0, sizeof(label));
        memset(label2, 0, sizeof(label2));
        int ans = 0;
        int n = grid1.size(), m = grid1[0].size();
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) {
                if (grid1[i][j] == 1 && label[i][j] == 0) 
                    bfs(grid1, i, j);
            }
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) {
                if (grid2[i][j] == 0 || label2[i][j] == 1) continue;
                if (bfs2(grid2, i, j))
                    ans++;
            }
        return ans;
    }
};
int main() {
    vector<vector<int>> grid1, grid2;
    int x;
    for (int i=0;i<5;i++) {
        grid1.push_back(vector<int>());
        for (int j=0;j<5;j++) {
            cin >> x;
            grid1[i].push_back(x);
        }
    }
    for (int i=0;i<5;i++) {
        grid2.push_back(vector<int>());
        for (int j=0;j<5;j++) {
            cin >> x;
            grid2[i].push_back(x);
        }
    }
    Solution s;
    cout << s.countSubIslands(grid1, grid2) << endl;
    return 0;
}