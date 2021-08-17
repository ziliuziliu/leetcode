#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int mp[505][505], to[505];

    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        for (int i=0;i<n;i++)
            for (int j=0;j<n-1;j++)
                mp[i][preferences[i][j]] = j;
        for (int i=0;i<n/2;i++) { to[pairs[i][0]] = pairs[i][1]; to[pairs[i][1]] = pairs[i][0]; }
        int ans = 0;
        for (int i=0;i<n;i++) {
            bool flag = false;
            for (int j=0;j<n;j++) {
                if (i == j || to[i] == j) continue;
                if (mp[i][to[i]] > mp[i][j] && mp[j][i] < mp[j][to[j]]) {
                    flag = true;
                    break;
                }
            }
            ans += flag;
        }
        return ans;
    }
};
int main() {
    int n, x;
    vector<vector<int>> preferences;
    vector<vector<int>> pairs;
    cin >> n;
    for (int i=0;i<n;i++) {
        preferences.push_back(vector<int>());
        for (int j=0;j<n-1;j++) {
            cin >> x;
            preferences[i].push_back(x);
        }
    }
    for (int i=0;i<n/2;i++) {
        pairs.push_back(vector<int>());
        for (int j=0;j<2;j++) {
            cin >> x;
            pairs[i].push_back(x);
        }
    }
    Solution s;
    cout << s.unhappyFriends(n, preferences, pairs) << endl;
    return 0;
}