#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    struct edge {
        int v, nxt;
    }e[40050];
    int d[10050] = {0}, g[10050] = {0}, nume = 1;

    void addedge(int u, int v) {
        e[++nume].v = v;
        e[nume].nxt = g[u];
        g[u] = nume;
    }

    vector<int> topo_sort(int n) {
        queue<int> q;
        vector<int> ans;
        for (int i=0;i<n;i++) if (!d[i]) q.push(i);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            ans.push_back(x);
            for (int i=g[x];i;i=e[i].nxt) {
                int v = e[i].v;
                d[v]--;
                if (!d[v]) q.push(v);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        for (int i=0;i<graph.size();i++) {
            for (int j=0;j<graph[i].size();j++) {
                addedge(graph[i][j], i);
                d[i]++;
            }
        }
        return topo_sort(graph.size());
    }
};
int main() {
    int a[8] = {0};
    for (int i=0;i<7;i++) cin >> a[i];
    vector<vector<int>> graph;
    Solution s;
    s.eventualSafeNodes(graph);
    return 0;
}