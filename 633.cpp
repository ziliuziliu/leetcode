#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long limit = sqrt(c);
        long long pos1 = 0, pos2 = limit;
        while (true) {
            while (pos1*pos1 + pos2*pos2 < c && pos1 < pos2)
                pos1++; 
            if (pos1*pos1 + pos2*pos2 == c) 
                return true;
            if (pos1 >= pos2) break;
            pos2--;
        }
        return false;
    }
};
int main() {
    int x;
    cin >> x;
    Solution s;
    cout << s.judgeSquareSum(x) << endl;
    return 0;
}