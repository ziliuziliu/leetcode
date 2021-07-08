#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    long long mod = 1e9+7;
    
    long long pow(long long a, long long b) {
        long long ans = 1LL, base = a;
        while (b) {
            if (b&1) ans = (ans * base) % mod;
            base = (base * base) % mod;
            b >>= 1;
        }
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        long long a, b; n--;
        if (n&1) {a = n/2+1; b = a;}
        else {a = n/2+1; b = a-1;}
        long long ans = pow(5, a) * pow(4, b) % mod;
        return (int)ans;
    }
};
int main() {
    long long n;
    cin >> n;
    Solution s;
    cout << s.countGoodNumbers(n) << endl;
    return 0;
}