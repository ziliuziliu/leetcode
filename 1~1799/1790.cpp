#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        char a1[2], a2[2];
        for (int i=0;i<s1.size();i++) {
            if (s1[i] != s2[i]) {
                if (cnt == 2) return false;
                a1[cnt] = s1[i]; a2[cnt] = s2[i];
                cnt += (s1[i] != s2[i]);
            }
        }
        if (cnt == 0) return true;
        if (cnt == 1) return false;
        return (a1[0] == a2[1]) && (a1[1] == a2[0]);
    }
};
int main() {
    Solution s;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << s.areAlmostEqual(s1, s2) << endl;
    return 0;
}