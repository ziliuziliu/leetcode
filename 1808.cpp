#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Solution {
public:
    long long pow(int a, int b) {
        long long ans = 1, mod = 1000000007, base = a;
        while (b) {
            if (b&1) ans = (ans*base)%mod;
            base = (base*base)%mod;
            b >>= 1;
        }
        return (int)ans;
    }
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 3) return primeFactors;
        int mod = 1000000007;
        long long ans = pow(3, primeFactors>=6 ? (primeFactors-6)/3+1 : 0);
        int rest = primeFactors%3+3;
        if (rest == 3) ans = (ans*3)%mod;
        else if (rest == 4) ans = (ans*4)%mod;
        else ans = (ans*6)%mod;
        return (int)ans;    
    }
};
int main() {
    int n;
    Solution s;
    cin >> n;
    cout << s.maxNiceDivisors(n) << endl;
    return 0;
}