#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l = 1, r = 1e6, ans = -1;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            long long ret = mid * (mid+1) / 2;
            long long total = (ret + ret + mid * (mid+1)) * (mid+1) / 2;
            total *= 4;
            total -= ret * 4;
            if (total >= neededApples) {
                ans = 8 * mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
int main() {
    long long neededApples;
    Solution s;
    cout << s.minimumPerimeter(neededApples) << endl;
    return 0;
}