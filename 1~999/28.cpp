#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        int next[50050], pos = 0;
        memset(next, 0, sizeof(next));
        for (int i=1;i<needle.length();i++) {
            while (pos && needle[i] != needle[pos])
                pos = next[pos];
            if (needle[i] == needle[pos]) pos++;
            next[i+1] = pos;
        }
        pos = 0;
        for (int i=0;i<haystack.length();i++) {
            while (pos && haystack[i] != needle[pos])
                pos = next[pos];
            if (haystack[i] == needle[pos]) pos++;
            if (pos == needle.length()) return i-needle.length()+1;
        }
        return -1;
    }
};
int main() {
    freopen("28.in", "r", stdin);
    freopen("28.out", "w", stdout);
    string haystack, needle;
    cin >> haystack >> needle;
    Solution s;
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}
