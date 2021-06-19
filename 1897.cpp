#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[30], n = words.size();
        for (int i=0;i<26;i++) cnt[i] = 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<words[i].length();j++)
                cnt[words[i][j]-'a']++;
        for (int i=0;i<26;i++) {
            if (cnt[i] % n != 0) return false;
        }
        return true;
    }
};
int main() {
    vector<string> words;
    string x;
    for (int i=0;i<3;i++) {
        cin >> x;
        words.push_back(x);
    }
    Solution s;
    cout << s.makeEqual(words) << endl;
    return 0;
}