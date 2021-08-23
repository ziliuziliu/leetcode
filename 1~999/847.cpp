#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    struct edge {
        int v, nxt;
    }e[1050];
    int g[1050] = {0}, nume = 1, dp[4100][13], n;
    bool vis[4100][13] = {false};
    
    void addedge(int u, int v) {
        e[++nume].v = v;
        e[nume].nxt = g[u];
        g[u] = nume;
    }

    int spfa() {
        queue<int> q;
        for (int i=0;i<n;i++) {
            dp[1<<i][i] = 0; vis[1<<i][i] = true;
            q.push(1<<i); q.push(i);
        }
        while (!q.empty()) {
            int s = q.front(); q.pop();
            int x = q.front(); q.pop();
            vis[s][x] = false;
            for (int i=g[x];i;i=e[i].nxt) {
                int v = e[i].v;
                if (dp[s|(1<<v)][v] > dp[s][x] + 1) {
                    dp[s|(1<<v)][v] = dp[s][x] + 1;
                    if (!vis[s|(1<<v)][v]) {
                        vis[s|(1<<v)][v] = true;
                        q.push(s|(1<<v)); q.push(v);
                    }
                }
            }
        }
        int ans = 1e9+7;
        for (int i=0;i<n;i++) ans = min(ans, dp[(1<<n)-1][i]);
        return ans;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        for (int i=0;i<n;i++) 
            for (int j=0;j<graph[i].size();j++) 
                addedge(i, graph[i][j]);
        for (int i=0;i<(1<<n);i++)
            for (int j=0;j<n;j++)
                dp[i][j] = 1e9+7;
        return spfa();
    }
};
int main() {
    vector<vector<int>> graph;
    int a[6];
    for (int i=0;i<6;i++) cin >> a[i];
    Solution s;
    cout << s.shortestPathLength(graph) << endl;
    return 0;
}