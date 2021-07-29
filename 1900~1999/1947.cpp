#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int n, m;
    bool vis[10];
    int match[10];
    
    int dfs(int x, vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ret = 0;
        if (x == m) {
            for (int i=0;i<m;i++)
                for (int j=0;j<n;j++)
                    ret += (students[i][j] == mentors[match[i]][j]);
            return ret;
        }
        for (int i=0;i<m;i++) {
            if (!vis[i]) {
                vis[i] = true; match[x] = i;
                ret = max(ret, dfs(x+1, students, mentors));
                vis[i] = false;
            }
        }
        return ret;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        m = students.size(); n = students[0].size();
        memset(vis, false, sizeof(vis));
        memset(match, 0, sizeof(match));
        return dfs(0, students, mentors);
    }
};
int main() {
    vector<vector<int>> students, mentors;
    int x;
    for (int i=0;i<3;i++) {
        students.push_back(vector<int>());
        for (int j=0;j<3;j++) {
            cin >> x;
            students[i].push_back(x);
        }
    }
    for (int i=0;i<3;i++) {
        mentors.push_back(vector<int>());
        for (int j=0;j<3;j++) {
            cin >> x;
            mentors[i].push_back(x);
        }
    }
    Solution s;
    cout << s.maxCompatibilitySum(students, mentors) << endl;
    return 0;
}