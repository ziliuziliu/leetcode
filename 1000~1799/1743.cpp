#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> mp;
        for (int i=0;i<adjacentPairs.size();i++)
            for (int j=0;j<2;j++) {
                if (!mp.count(adjacentPairs[i][j])) mp[adjacentPairs[i][j]] = vector<int>();
                mp[adjacentPairs[i][j]].push_back(i);
            }
        vector<int> ans; int b = 0, pos = -1;
        for (map<int, vector<int>>::iterator it = mp.begin(); it != mp.end(); it++) {
            if (it->second.size() == 1) {
                b = it->first;
                break;
            }
        }
        while (true) {
            ans.push_back(b);
            if (ans.size() == adjacentPairs.size() + 1) break;
            if (mp[b][0] != pos) pos = mp[b][0];
            else pos = mp[b][1];
            if (adjacentPairs[pos][0] != b) b = adjacentPairs[pos][0];
            else b = adjacentPairs[pos][1];
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> adjacentPairs;
    int x;
    for (int i=0;i<3;i++) { 
        adjacentPairs.push_back(vector<int>());
        for (int j=0;j<2;j++) {
            cin >> x;
            adjacentPairs[i].push_back(x);
        }
    }
    Solution s;
    s.restoreArray(adjacentPairs);
    return 0;
}