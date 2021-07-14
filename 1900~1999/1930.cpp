#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> cnt[26];
        for (int i=0;i<26;i++) {
            if (s[0]-'a' == i) cnt[i].push_back(1);
            else cnt[i].push_back(0);
        }
        int n = s.length();
        for (int i=1;i<n;i++) 
            for (int j=0;j<26;j++) {
                if (s[i]-'a' == j) cnt[j].push_back(cnt[j][i-1]+1);
                else cnt[j].push_back(cnt[j][i-1]);
            }
        bool vis[26][26];
        memset(vis, false, sizeof(vis));
        for (int i=1;i<n-1;i++) {
            int now = s[i] - 'a';
            for (int j=0;j<26;j++) {
                int prev = cnt[j][i-1], next = cnt[j][n-1] - cnt[j][i];
                if (prev > 0 && next > 0) vis[now][j] = true;
            }
        }
        int ans = 0;
        for (int i=0;i<26;i++)
            for (int j=0;j<26;j++)
                ans += vis[i][j];
        return ans;
    }
};
int main() {
    string s;
    cin >> s;
    Solution so;
    cout << so.countPalindromicSubsequence(s) << endl;
    return 0;
}