#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int pow(long long a, long long b, long long mod) {
        long long ans = 1, base = a;
        while (b) {
            if (b & 1) ans = ans * base % mod;
            base = base * base % mod;
            b >>= 1;
        }
        return ans;
    }
    
    int minNonZeroProduct(int p) {
        long long ret = 1, mod = 1e9 + 7, a, b, c;
        if (p == 1) return 1;
        for (int i=1;i<=p-1;i++) ret <<= 1;
        a = ((ret << 1) - 2) % mod;
        b = ret - 1;
        c = ((ret << 1) - 1) % mod;
        return pow(a, b, mod) * c % mod; 
    }
};
int main() {
    int p;
    cin >> p;
    Solution s;
    cout << s.minNonZeroProduct(p) << endl;
    return 0;
}