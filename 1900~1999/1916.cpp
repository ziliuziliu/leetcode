#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int mod = 1e9+7;
    int dp[100050], size[100050];
    int fac[100050], inv[100050];
    struct edge {
        int v, nxt;
    }e[200050];
    int g[100050], nume = 1;
    
    int mul(int a, int b) {
        long long t = (long long)a*b;
        return t%mod;
    }
    
    int pow(int a, int b) {
        int ans = 1, base = a;
        while (b) {
            if (b&1) ans = mul(ans, base);
            base = mul(base, base);
            b >>= 1;
        }
        return ans;
    }
    
    void build(int n) {
        fac[0] = 1;
        for (int i=1;i<=n;i++) fac[i] = mul(fac[i-1], i);
        inv[n] = pow(fac[n], mod-2);
        for (int i=n-1;i>=0;i--) inv[i] = mul(inv[i+1], i+1);
    }
    
    void addedge(int u, int v) {
        e[++nume].v = v;
        e[nume].nxt = g[u];
        g[u] = nume;
    }
    
    void dfs(int x) {
        for (int i=g[x];i;i=e[i].nxt) {
            int v = e[i].v;
            dfs(v);
            size[x] += size[v];
        }
        dp[x] = fac[size[x]-1];
        for (int i=g[x];i;i=e[i].nxt) {
            int v = e[i].v;
            dp[x] = mul(dp[x], inv[size[v]]);
            dp[x] = mul(dp[x], dp[v]);
        }
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        build(n);
        for (int i=0;i<n;i++) { dp[i] = 1; size[i] = 1; }
        memset(g, 0, sizeof(g));
        for (int i=1;i<n;i++) addedge(prevRoom[i], i);
        dfs(0);
        return dp[0];
    }
};
int main() {
    int x;
    vector<int> prevRooms;
    for (int i=0;i<3;i++) {
        cin >> x;
        prevRooms.push_back(x);
    }
    Solution s;
    cout << s.waysToBuildRooms(prevRooms) << endl;
    return 0;
}