#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for (int i=0;i<piles.size();i++) q.push(piles[i]);
        for (int i=0;i<k;i++) {
            int top = q.top(); q.pop();
            q.push(top - top/2);
        }
        int ans = 0;
        while (!q.empty()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};
int main() {
    int k, x;
    vector<int> piles;
    for (int i=0;i<3;i++) {
        cin >> x;
        piles.push_back(x);
    }
    cin >> k;
    Solution s;
    cout << s.minStoneSum(piles, k) << endl;
    return 0;
}