#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int cnt1 = 0, cnt2 = 0, mask;
        int ans = 0;
        for (int i=0;i<=30;i++) {
            cnt1 = cnt2 = 0;
            for (int j=0;j<arr1.size();j++) cnt1 += ((arr1[j] >> i) & 1);
            for (int j=0;j<arr2.size();j++) cnt2 += ((arr2[j] >> i) & 1);
            ans += (((cnt1&1) & (cnt2&1)) << i);
        }
        return ans;
    }
};
int main() {
    vector<int> arr1, arr2;
    int x;
    for (int i=0;i<1;i++) {
        cin >> x;
        arr1.push_back(x);
    }
    for (int i=0;i<1;i++) {
        cin >> x;
        arr2.push_back(x);
    }
    Solution s;
    cout << s.getXORSum(arr1, arr2) << endl;
    return 0;
}