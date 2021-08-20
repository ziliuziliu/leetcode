#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        vector<int> v;
        for (int i=0;i<s.length();i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                v.push_back(i);
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                v.push_back(i);
        }
        int n = v.size();
        for (int i=0;i<n/2;i++) swap(s[v[i]], s[v[n-1-i]]);
        return s; 
    }
};
int main() {
    string s;
    Solution so;
    cin >> s;
    cout << so.reverseVowels(s) << endl;
    return 0;
}