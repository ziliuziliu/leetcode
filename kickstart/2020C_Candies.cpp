#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
int T, n, q, a[maxn], sum1[maxn], sum2[maxn], l, r, x, v, cnt = 0, root;
char type;
long long ans = 0;
struct node {
    int ls, rs;
    long long sum1, sum2, lazy1, lazy2;
} tree[maxn << 2];
void pushup(int now) {
    int ls = tree[now].ls, rs = tree[now].rs;
    tree[now].sum1 = tree[ls].sum1 + tree[rs].sum1;
    tree[now].sum2 = tree[ls].sum2 + tree[rs].sum2;
}
void pushdown(int now, int left, int right) {
    if (!tree[now].lazy1 && !tree[now].lazy2) return;
    int ls = tree[now].ls, rs = tree[now].rs, mid = (left + right) >> 1;
    tree[ls].sum1 += tree[now].lazy1 * (mid - left + 1); tree[ls].lazy1 += tree[now].lazy1;
    tree[rs].sum1 += tree[now].lazy1 * (right - mid); tree[rs].lazy1 += tree[now].lazy1;
    tree[now].lazy1 = 0;
    tree[ls].sum2 += tree[now].lazy2 * (mid - left + 1); tree[ls].lazy2 += tree[now].lazy2;
    tree[rs].sum2 += tree[now].lazy2 * (right - mid); tree[rs].lazy2 += tree[now].lazy2;
    tree[now].lazy2 = 0;
}
void build(int &now, int left, int right) {
    now = ++cnt;
    tree[now].ls = tree[now].rs = 0;
    tree[now].sum1 = tree[now].sum2 = tree[now].lazy1 = tree[now].lazy2 = 0;
    if (left == right) {
        tree[now].sum1 = sum1[left]; tree[now].sum2 = sum2[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(tree[now].ls, left, mid);
    build(tree[now].rs, mid+1, right);
    pushup(now);
}
long long query(int now, int left, int right, int l, int r, int type) {
    pushdown(now, left, right);
    if (left == l && right == r)
        return type == 1 ? tree[now].sum1 : tree[now].sum2;
    int mid = (left + right) >> 1;
    if (r <= mid) return query(tree[now].ls, left, mid, l, r, type);
    else if (l >= mid + 1) return query(tree[now].rs, mid+1, right, l, r, type);
    else return query(tree[now].ls, left, mid, l, mid, type) 
            + query(tree[now].rs, mid+1, right, mid+1, r, type);
}
void update(int now, int left, int right, int l, int r, int val, int type) {
    pushdown(now, left, right);
    if (left == l && right == r) {
        if (type == 1) {
            tree[now].sum1 += (right - left + 1) * val;
            tree[now].lazy1 += val;
        }
        else {
            tree[now].sum2 += (right - left + 1) * val;
            tree[now].lazy2 += val;
        }
        return;
    }
    int mid = (left + right) >> 1;
    if (r <= mid) update(tree[now].ls, left, mid, l, r, val, type);
    else if (l >= mid+1) update(tree[now].rs, mid+1, right, l, r, val, type);
    else {
        update(tree[now].ls, left, mid, l, mid, val, type);
        update(tree[now].rs, mid+1, right, mid+1, r, val, type);
    }
    pushup(now);
}
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        cnt = ans = 0; 
        memset(sum1, 0, sizeof(sum1)); memset(sum2, 0, sizeof(sum2));
        scanf("%d%d", &n, &q);
        for (int i=1;i<=n;i++) scanf("%d", &a[i]);
        for (int i=n;i>=1;i--) sum1[i] = sum1[i+1] + a[i] * (i&1 ? 1 : -1);
        for (int i=n;i>=1;i--) sum2[i] = sum2[i+1] + a[i] * (i&1 ? -1 : 1);
        build(root, 1, n);
        for (int i=1;i<=q;i++) {
            scanf("%s", &type);
            if (type == 'Q') {
                scanf("%d%d", &l, &r);
                ans += query(root, 1, n, l, r, l&1 ? 1 : 2);
                if (r < n) 
                    ans -= query(root, 1, n, r+1, r+1, l&1 ? 1 : 2) * (r - l + 1);
            }
            else {
                scanf("%d%d", &x, &v);
                update(root, 1, n, 1, x, (v - a[x]) * (x&1 ? 1 : -1), 1);
                update(root, 1, n, 1, x, (a[x] - v) * (x&1 ? 1 : -1), 2);
                a[x] = v;
            }
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}