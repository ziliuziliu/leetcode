#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    struct edge {
        int v, w, nxt;
    }e[50050];
    int g[105], nume = 1, dis[105][105];
    bool vis[105][105];
    
    void addedge(int u, int v, int w) { e[++nume].v = v; e[nume].w = w; e[nume].nxt = g[u]; g[u] = nume; }

    int spfa(int n, int src, int dst, int k) {
        for (int i=0;i<n;i++)
            for (int j=0;j<=k+1;j++)
                dis[i][j] = 1e9+7;
        queue<int> q; q.push(src); q.push(0); dis[src][0] = 0;
        while (!q.empty()) {
            int x = q.front(); q.pop(); int num = q.front(); q.pop();
            if (num == k+1) continue;
            for (int i=g[x];i;i=e[i].nxt) {
                int v = e[i].v, w = e[i].w;
                if (dis[v][num+1] > dis[x][num] + w) {
                    dis[v][num+1] = dis[x][num] + w;
                    if (!vis[v][num+1]) { vis[v][num+1] = true; q.push(v); q.push(num+1); }
                }
            }
        }
        int ans = 1e9+7;
        for (int i=0;i<=k+1;i++) ans = min(ans, dis[dst][i]);
        return ans > 1e9 ? -1 : ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for (int i=0;i<flights.size();i++) addedge(flights[i][0], flights[i][1], flights[i][2]);
        return spfa(n, src, dst, k);
    }
};
int main() {
    int n, src, dst, k, x; vector<vector<int>> flights;
    cin >> n;
    for (int i=0;i<3;i++) {
        flights.push_back(vector<int>());
        for (int j=0;j<3;j++) {
            cin >> x;
            flights[i].push_back(x);
        }
    }
    cin >> src >> dst >> k;
    Solution s;
    cout << s.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}