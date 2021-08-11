#include<bits/stdc++.h>
#define maxn 5000050
using namespace std;
int T, n, k, root = 1, tree[maxn][26], cnt[maxn], total = 1;
string s;
void insert(int &x, int id) {
    if (!x) x = ++total;
    cnt[x]++;
    if (id == s.length()) return;
    insert(tree[x][s[id] - 'A'], id + 1);
}
int query() {
    queue<int> q; q.push(root);
    int ret = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x != root) ret += cnt[x] / k;
        for (int i=0;i<26;i++)
            if (tree[x][i]) q.push(tree[x][i]);
    }
    return ret;
}
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        for (int i=1;i<=total;i++) {
            for (int j=0;j<26;j++) tree[i][j] = 0;
            cnt[i] = 0;
        }
        total = 1;
        scanf("%d%d", &n, &k);
        for (int i=1;i<=n;i++) {
            cin >> s;
            insert(root, 0);
        }
        printf("Case #%d: %d\n", t, query());
    }
    return 0;
}