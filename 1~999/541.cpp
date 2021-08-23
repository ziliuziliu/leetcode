#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int i;
        for (i=0;i+k<=s.length();i+=2*k)
            for (int j=0;j<k/2;j++)
                swap(s[i+j], s[i+k-1-j]);
        if (i < s.length()) {
            int len = s.length() - i;
            for (int j=0;j<len/2;j++)
                swap(s[i+j], s[i+len-1-j]);
        }
        return s;
    }
};
int main() {
    string x; int k;
    Solution s;
    cout << s.reverseStr(x, k) << endl;
    return 0;
}