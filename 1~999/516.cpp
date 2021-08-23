#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int dp[1050][1050] = {0};
    int longestPalindromeSubseq(string s) {
        for (int i=0;i<s.length();i++) dp[i][i] = 1;
        for (int l=1;l<s.length();l++)
            for (int i=0;i<s.length()-l;i++) {
                dp[i][i+l] = max(dp[i+1][i+l], dp[i][i+l-1]);
                if (s[i] == s[i+l]) dp[i][i+l] = max(dp[i][i+l], dp[i+1][i+l-1] + 2);
            }
        return dp[0][s.length()-1];
    }
};
int main() {
    string s;
    Solution so;
    cin >> s;
    cout << so.longestPalindromeSubseq(s) << endl;
    return 0;
}