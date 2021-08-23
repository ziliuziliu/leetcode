#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), ans = 0;
        for (int i=1;i<=n;i++) {
            if (i <= citations[n-i])
                ans = i;
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