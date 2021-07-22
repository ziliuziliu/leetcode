#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mx = 0;
        for (int i=0;i<n;i++) mx = min(mx + 1, arr[i]);
        return mx;
    }
};
int main() {
    int x;
    vector<int> arr;
    for (int i=0;i<5;i++) {
        cin >> x;
        arr.push_back(x);
    }
    Solution s;
    cout << s.maximumElementAfterDecrementingAndRearranging(arr) << endl;
    return 0;
}