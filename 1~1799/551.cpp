#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkRecord(string s) {
        int cnt = 0;
        for (int i=0;i<s.length();i++) {
            cnt += s[i] == 'A';
            if (i >= 2 && s[i] == s[i-1] && s[i-1] == s[i-2] && s[i-2] == 'L')
                return false;   
        }
        return cnt < 2;
    }
};
int main() {
    Solution s;
    string so;
    cout << s.checkRecord(so) << endl;
    return 0;
}