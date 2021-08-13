#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        int ret = 0, ans = 0;
        for (int i=0;i<s.length();i++) {
            if (s[i] == '[') ret++;
            else ret--;
            if (ret < 0) ans = max(ans, (int)ceil((double)(-ret)/2));
        } 
        return ans;
    }
};
int main() {
    string x;
    Solution s;
    cin >> x;
    cout << s.minSwaps(x) << endl;
    return 0;
}