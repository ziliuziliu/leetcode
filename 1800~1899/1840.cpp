#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2)
    {
	    return v1[0] < v2[0];//升序排列  
    }
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int inf = 1000000007;
        int vall[100050], valr[100050], size = restrictions.size();
        if (size == 0) return n-1;
        sort(restrictions.begin(), restrictions.end(), cmp);
        int prevHeight = 0, prevPos = 1;
        int ans = 0;
        for (int i=0;i<size;i++) {
            vall[i] = min(restrictions[i][1], prevHeight + (restrictions[i][0] - prevPos));
            prevHeight = vall[i];
            prevPos = restrictions[i][0];
        }
        prevHeight = inf; prevPos = size;
        for (int i=size-1;i>=0;i--) {
            valr[i] = min(restrictions[i][1], prevHeight + (prevPos - restrictions[i][0]));
            prevHeight = valr[i];
            prevPos = restrictions[i][0];
        }
        int x = ((valr[0] - 0) + restrictions[0][0] + 1) / 2;
        ans = max(ans, min(x-1, valr[0]+restrictions[0][0]-x));
        for (int i=0;i<size-1;i++) {
            x = ((valr[i+1] - vall[i]) + restrictions[i][0] + restrictions[i+1][0]) / 2;
            x = max(x, restrictions[i][0]);
            x = min(x, restrictions[i+1][0]);
            ans = max(ans, min(vall[i]+x-restrictions[i][0], valr[i+1]+restrictions[i+1][0]-x));
        }
        ans = max(ans, min(vall[size-1], valr[size-1])+(n-restrictions[size-1][0]));
        return ans;
    }
};
int main() {
    int n;
    vector<vector<int>> restrictions;
    cin >> n;
    for (int i=0;i<2;i++) {
        restrictions.push_back(vector<int>());
        for (int j=0;j<2;j++) {
            int x;
            cin >> x;
            restrictions[i].push_back(x);
        }
    }
    Solution s;
    cout << s.maxBuilding(n, restrictions) << endl;
    return 0;
}