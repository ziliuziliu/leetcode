#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int dp[1000050] = {0}, pointer[105] = {0};

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        dp[1] = 1;
        for (int i=0;i<primes.size();i++) pointer[i] = 1;
        for (int i=2;i<=n;i++) {
            int mn = 2e9+7;
            for (int j=0;j<primes.size();j++) mn = min(mn, dp[pointer[j]] * primes[j]);
            dp[i] = mn;
            for (int j=0;j<primes.size();j++) 
                if (dp[pointer[j]] * primes[j] == mn)
                    pointer[j]++;
        }
        return dp[n];
    }
};
int main() {
    int n, x;
    vector<int> primes;
    cin >> n;
    for (int i=0;i<4;i++) {
        cin >> x;
        primes.push_back(x);
    }
    Solution s;
    cout << s.nthSuperUglyNumber(n, primes) << endl;
    return 0;
}