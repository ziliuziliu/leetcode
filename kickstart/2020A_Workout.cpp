#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
int T, n, k, m[maxn];
bool check(int x) {
    int ret = 0;
    for (int i=1;i<n;i++) ret += ceil((double)(m[i+1] - m[i]) / x) - 1;
    return ret <= k;
}
int search() {
    int left = 1, right = 0, ans = -1;
    for (int i=1;i<n;i++) right = max(right, m[i+1] - m[i]);
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (check(mid)) {ans = mid; right = mid - 1;}
        else left = mid + 1;
    }
    return ans;
}
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        scanf("%d%d", &n, &k);
        for (int i=1;i<=n;i++) scanf("%d", &m[i]);
        printf("Case #%d: %d\n", t, search());
    }
    return 0;
}