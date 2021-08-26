#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    void dfs(int x, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans) {
        if (x == graph.size() - 1) {
            ans.push_back(path);
            return;
        }
        for (int i=0;i<graph[x].size();i++) {
            int v = graph[x][i];
            path.push_back(v);
            dfs(v, graph, path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans; vector<int> path; path.push_back(0);
        dfs(0, graph, path, ans);
        return ans;
    }
};
int main() {
    vector<vector<int>> graph;
    Solution s;
    s.allPathsSourceTarget(graph);
    return 0;
}