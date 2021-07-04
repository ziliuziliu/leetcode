#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:

    bool check(int k, string s, string p, vector<int>& removable) {
        string c;
        bool remove[100050];
        memset(remove, 0, sizeof(remove));
        for (int i=0;i<k;i++) remove[removable[i]] = true;
        int pos = 0;
        for (int i=0;i<s.size();i++) {
            if (remove[i]) continue;
            if (s[i] == p[pos]) pos++;
            if (pos == p.length()) return true;
        }
        return false;
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size(), ans;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (check(mid, s, p, removable)) {ans = mid; left = mid+1;}
            else right = mid-1;
        }
        return ans;
    }
};
int main() {
    string s, p;
    vector<int> removable;
    int x;
    cin >> s >> p;
    for (int i=0;i<3;i++) {
        cin >> x;
        removable.push_back(x);
    }
    Solution so;
    cout << so.maximumRemovals(s, p, removable) << endl;
    return 0;
}