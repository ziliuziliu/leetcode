#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    struct edge {
        int v, w, nxt;
    }e[6050];
    int g[105], nume = 1;
    
    void addedge(int u, int v, int w) {
        e[++nume].v = v;
        e[nume].w = w;
        e[nume].nxt = g[u];
        g[u] = nume;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (int i=0;i<times.size();i++) addedge(times[i][0], times[i][1], times[i][2]);
        queue<int> q; q.push(k);
        int ans = 0, dis[105]; bool vis[105] = {0};
        for (int i=1;i<=n;i++) dis[i] = 1e9+7; dis[k] = 0; vis[k] = true;
        while (!q.empty()) {
            int x = q.front(); q.pop(); vis[x] = false;
            for (int i=g[x];i;i=e[i].nxt) {
                int v = e[i].v;
                if (dis[v] > dis[x] + e[i].w) {
                    dis[v] = dis[x] + e[i].w;
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        } 
        for (int i=1;i<=n;i++) ans = max(ans, dis[i]);
        ans = (ans > 1e9) ? -1 : ans;
        return ans;
    }
};
int main() {
    vector<vector<int>> times;
    int x, n, k;
    for (int i=0;i<3;i++) {
        times.push_back(vector<int>());
        for (int j=0;j<3;j++) {
            cin >> x;
            times[i].push_back(x);
        }
    }
    cin >> n >> k;
    Solution s;
    cout << s.networkDelayTime(times, n, k) << endl;
    return 0;
}