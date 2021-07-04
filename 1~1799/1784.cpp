#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class Solution {
public:
    bool checkOnesSegment(string s) {
        int index = 0;
        bool ans = false;
        while (index < s.size() && s[index] == '1') 
            index++;
        while (index < s.size() && s[index] == '0')
            index++;
        return index == s.size();
    }
};
int main() {
    Solution s;
    string str;
    cin >> str;
    cout << s.checkOnesSegment(str) << endl;
    return 0;
}