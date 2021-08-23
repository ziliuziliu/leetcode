#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = citations.size()-1, ans = 0;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (n - mid <= citations[mid]) {
                ans = n - mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
int main() {
    vector<int> citations;
    int x;
    for (int i=0;i<5;i++) {
        cin >> x;
        citations.push_back(x);
    }
    Solution s;
    cout << s.hIndex(citations) << endl;
    return 0;
}