#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> standard;
        for (int i=0;i<dist.size();i++) standard.push_back((int)ceil((double)dist[i]/speed[i]));
        sort(standard.begin(), standard.end());
        int ans = 0;
        for (int i=0;i<standard.size();i++) {
            if (ans >= standard[i]) break;
            ans++;
        }
        return ans;
    }
};
int main() {
    vector<int> dist, speed;
    int x;
    for (int i=0;i<3;i++) {
        cin >> x;
        dist.push_back(x);
    }
    for (int i=0;i<3;i++) {
        cin >> x;
        speed.push_back(x);
    }
    Solution s;
    cout << s.eliminateMaximum(dist, speed) << endl;
    return 0;
}