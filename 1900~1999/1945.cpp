#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLucky(string s, int k) {
        string s2;
        for (int i=0;i<s.length();i++) {
            int num = s[i] - 'a' + 1;
            if (num <= 9) s2.append(1, '0'+num);
            else if (num <=19) {s2.append(1, '1'); s2.append(1, '0'+num-10);}
            else {s2.append(1, '2'); s2.append(1, '0'+num-20);}
        }
        int ret = 0;
        for (int i=1;i<=k;i++) {
            ret = 0;
            for (int j=0;j<s2.length();j++) ret += s2[j] - '0';
            s2 = to_string(ret);
        }
        return atoi(s2.c_str());
    }
};
int main() {
    string s; int k;
    Solution so;
    cout << so.getLucky(s, k) << endl;
    return 0;
}