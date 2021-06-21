#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int pos = -1;
        for (int i=0;i<num.length();i++) {
            int bit = num[i] - '0';
            if (bit&1) pos = i;
        }
        if (pos == -1) return "";
        return num.substr(0, pos+1);
    }
};
int main() {
    string num;
    cin >> num;
    Solution s;
    cout << s.largestOddNumber(num) << endl;
    return 0;
}