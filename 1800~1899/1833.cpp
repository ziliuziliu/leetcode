#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (int i=0;i<costs.size();i++) {
            if (coins < costs[i]) break;
            coins -= costs[i];
            ans++;
        }
        return ans;
    }
};
int main() {
    int x, coins;
    vector<int> costs;
    for (int i=0;i<5;i++) {
        cin >> x;
        costs.push_back(x);
    }
    cin >> coins;
    Solution s;
    cout << s.maxIceCream(costs, coins) << endl;
    return 0;
}