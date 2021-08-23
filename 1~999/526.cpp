#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int ans = 0;
    bool vis[20] = {false};

    void dfs(int pos, int n) {
        if (pos == n+1) {
            ans++;
            return;
        }
        for (int i=1;i<=n;i++) {
            if (vis[i]) continue;
            if ((i%pos == 0) || (pos%i == 0)) {
                vis[i] = true;
                dfs(pos+1, n);
                vis[i] = false;
            }
        }
    }

    int countArrangement(int n) {
        dfs(1, n);
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.countArrangement(n) << endl;
    return 0;
}