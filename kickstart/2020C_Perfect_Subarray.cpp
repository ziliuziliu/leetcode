#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
int T, n, a[maxn];
unordered_map<int, int> mp;
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        mp.clear(); 
        int mxsum = 0, sum = 0; long long ans = 0;
        scanf("%d", &n);
        for (int i=1;i<=n;i++) scanf("%d", &a[i]);
        mp[0] = 1;
        for (int i=1;i<=n;i++) {
            sum += a[i]; mxsum += abs(a[i]);
            for (int j=0;j*j<=mxsum;j++) {
                if (mp.count(sum - j*j))
                    ans += mp[sum - j*j];
            }
            if (!mp.count(sum)) mp[sum] = 0;
            mp[sum]++;
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}