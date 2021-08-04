#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        sort(milestones.begin(), milestones.end());
        long long ans = 0;
        for (int i=0;i<milestones.size()-1;i++) ans += (long long) milestones[i];
        ans += min(ans+1, (long long)milestones[milestones.size()-1]);
        return ans;
    }
};
int main() {
    int x;
    vector<int> milestones;
    for (int i=0;i<3;i++) {
        cin >> x;
        milestones.push_back(x);
    }
    Solution s;
    cout << s.numberOfWeeks(milestones) << endl;
    return 0;
}