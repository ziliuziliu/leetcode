#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (int i=1;i<=n;i++) cnt += (n%i == 0);
        return cnt == 3;
    }
};
int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.isThree(n) << endl;
    return 0;
}