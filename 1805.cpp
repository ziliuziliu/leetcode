#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
class Solution {
public:
    int isnumber(char s) {
        return s>='0' && s<='9';
    }
    int numDifferentIntegers(string word) {
        set<string> s;
        int start = 0, end;
        int ans = 0;
        while (start < word.length()) {
            if (!isnumber(word[start])) {
                start++;
                continue;
            }
            bool zeros = false;
            while (word[start] == '0' && start < word.length()) {
                zeros = true;
                start++;
            }
            if (start == word.length() || !isnumber(word[start])) {
                ans += !s.count("0");
                s.insert("0");
                continue;
            }
            end = start;
            while (end < word.length() && isnumber(word[end]))
                end++;
            ans += !s.count(word.substr(start, end-start));
            s.insert(word.substr(start, end-start));
            start = end;
        }
        return ans;
    }
};
int main() {
    string word;
    cin >> word;
    Solution s;
    cout << s.numDifferentIntegers(word) << endl;
    return 0;
}