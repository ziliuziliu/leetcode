#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ans = "";
        for (int i=0;i<words.size();i++) {
            ans.append(words[i]);
            if (ans == s) return true;
        }
        return false;
    }
};
int main() {
    string s, x;
    vector<string> v;
    cin >> s;
    for (int i=0;i<4;i++) {
        cin >> x;
        v.push_back(x);
    }
    Solution so;
    cout << so.isPrefixString(s, v) << endl;
    return 0;
}