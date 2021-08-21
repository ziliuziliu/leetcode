#include<bits/stdc++.h>
#define maxn 200050
#define eps 1e-7
using namespace std;
int T, n, m, xl, yl, xm, ym;
double table[maxn] = {0};
bool outofmap(int x, int y) { return x < 1 || x > n || y < 1 || y > m; }
int boundary(int x, int y) {
    if (x == n && y >= 2) return 1;
    if (y == m && x >= 2) return 2;
    return 0;
}
double getans(int x, int y) {
    int bflag = boundary(x, y);
    if (!bflag) {
        double logans = table[x+y-2] - table[x-1] - table[y-1];
        return pow(2, logans - x - y + 2);
    }
    if (bflag == 1) return getans(x, y - 1) + 0.5 * getans(x - 1, y);
    else return getans(x - 1, y) + 0.5 * getans(x, y - 1);
}
int main() {
    for (int i=2;i<maxn;i++) table[i] = table[i-1] + log2(i); 
    cin >> T;
    for (int t=1;t<=T;t++) {
        double ans = 0;
        cin >> m >> n >> yl >> xl >> ym >> xm;
        for (int i=1;;i++) {
            if (outofmap(xm + i, yl - i)) break;
            ans += getans(xm + i, yl - i);
        }
        for (int i=1;;i++) {
            if (outofmap(xl - i, ym + i)) break;
            ans += getans(xl - i, ym + i);
        }
        printf("Case #%d: %.6lf\n", t, ans);
    }
    return 0;
}