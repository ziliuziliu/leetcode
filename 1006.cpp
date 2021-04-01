#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Solution {
public:
    int clumsy(int N) {
        int ans = 0, i, flag;
        for (i=N;i>=4;i-=4) {
            flag = (i==N) ? 1 : -1;
            ans += flag*i*(i-1)/(i-2);
            ans += i-3;
        }
        flag = (i==N) ? 1 : -1;
        if (i==3) ans += 6*flag;
        else if (i==2) ans += 2*flag;
        else if (i==1) ans += 1*flag;
        return ans;
    }
};
int main() {
    Solution s;
    int N;
    cin >> N;
    cout << s.clumsy(N) << endl;
    return 0;
}