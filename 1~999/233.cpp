#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int dp[20] = {0}, table[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    int bits[10] = {0}, cnt = 0, ans = 0, left[10];

    void getBits(int n) {
        int x = n;
        while (n) {
            bits[cnt++] = n % 10;
            n /= 10;
        }
        for (int i=0;i<cnt;i++) left[i] = x % table[i];
    }

    int dfs(int id) {
        int bit = bits[id];
        if (id == 0) return bit >= 1;
        if (bit == 0) return dfs(id-1);
        if (bit == 1) return dp[id] + dfs(id-1) + left[id] + 1;
        return bit*dp[id] + dfs(id-1) + table[id];
        
    }

    int countDigitOne(int n) {
        if (n == 0) return 0;
        dp[1] = 1;
        for (int i=2;i<=9;i++) dp[i] = dp[i-1] * 10 + table[i-1];
        getBits(n);
        return dfs(cnt-1);
    }
};
int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.countDigitOne(n) << endl;
    return 0;
}