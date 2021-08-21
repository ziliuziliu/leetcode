#include<bits/stdc++.h>
using namespace std;
int T, n, m;
char s[35];
bool mp[35][35];
vector<pair<int, int>> pos[26];
vector<char> ans;
void flush_map(int now, bool flag) {
    for (int i=0;i<pos[now].size();i++)
        mp[pos[now][i].first][pos[now][i].second] = flag;
}
bool dfs(int total) {
    if (!total) return true;
    for (int i=0;i<26;i++) {
        if (pos[i].size() == 0) continue;
        if (mp[pos[i][0].first][pos[i][0].second]) continue;
        bool flag = true;
        flush_map(i, true);
        for (int j=0;j<pos[i].size();j++) {
            int nowX = pos[i][j].first, nowY = pos[i][j].second;
            if (nowX != n && !mp[nowX + 1][nowY]) {
                flag = false;
                break;
            }
        }
        if (!flag) { flush_map(i, false); continue; }
        ans.push_back('A' + i);
        if (dfs(total - pos[i].size())) return true;
        flush_map(i, false); ans.pop_back(); 
    }
    return false;
}
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        for (int i=0;i<26;i++) pos[i].clear(); ans.clear();
        memset(mp, false, sizeof(mp));
        scanf("%d%d", &n, &m);
        for (int i=1;i<=n;i++) {
            scanf("%s", s);
            for (int j=0;j<m;j++) 
                pos[s[j] - 'A'].push_back(make_pair(i, j + 1));
        }
        printf("Case #%d: ", t);
        if (dfs(n*m)) {
            for (int i=0;i<ans.size();i++)
                printf("%c", ans[i]); 
        }
        else printf("-1");
        printf("\n");
    }
    return 0;
}