#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.length();
        long long ans = 0;
        int cnt[10050]; memset(cnt, 0, sizeof(cnt));
        vector<int> a; a.push_back(0);
        for (int i=0;i<n;i++) a.push_back(1<<(word[i]-'a'));
        for (int i=1;i<=n;i++) a[i] ^= a[i-1];
        for (int i=1;i<=n;i++) cnt[a[i]]++;
        for (int i=0;i<n;i++) {
            for (int j=0;j<10;j++) {
                int modified = a[i]^(1<<j);
                ans += (long long)cnt[modified];
            }
            ans += (long long)cnt[a[i]];
            cnt[a[i+1]]--;
        }
        return ans;
    }
};
int main() {
    string word;
    cin >> word;
    Solution s;
    cout << s.wonderfulSubstrings(word) << endl;
    return 0;
}