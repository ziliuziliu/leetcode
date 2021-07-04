#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Solution {
public:
    int reinitializePermutation(int n) {
        int p = 1, ans = 0;
        do {
            p = (p < n/2) ? p*2 : p*2+1-n;
            ans++;
        } while (p != 1);
        return ans;
    }
};
int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.reinitializePermutation(n) << endl;
    return 0;
}