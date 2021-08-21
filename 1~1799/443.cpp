#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int tail = 0, left = 0, right = 0;
        int bits[5], cnt = 0, len;
        while (left < chars.size()) {
            while (right < chars.size() && chars[left] == chars[right]) right++;
            chars[tail++] = chars[left]; len = right - left;
            cnt = 0;
            if (len > 1)
                while (len) { bits[cnt++] = len % 10; len /= 10; }
            for (int i = cnt - 1; i >= 0; i--)
                chars[tail++] = bits[i] + '0';
            left = right;
        }
        return tail;
    }
};
int main() {
    char x; vector<char> chars;
    for (int i=0;i<7;i++) {
        cin >> x;
        chars.push_back(x);
    }
    Solution s;
    cout << s.compress(chars) << endl;
    return 0;
}