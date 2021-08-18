#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    struct RowItem {
        int cnt, id;
        RowItem(int cnt, int id):cnt(cnt),id(id) {}
        bool operator < (const RowItem &x) const {
            if (this->cnt != x.cnt) return this->cnt < x.cnt;
            return this->id < x.id;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<RowItem> v;
        vector<int> ans;
        for (int i=0;i<n;i++) {
            int cnt = 0;
            for (int j=0;j<m;j++) cnt += mat[i][j];
            v.push_back(RowItem(cnt, i));
        }
        sort(v.begin(), v.end());
        for (int i=0;i<k;i++) ans.push_back(v[i].id);
        return ans;
    }
};
int main() {
    int x, k;
    vector<vector<int>> mat;
    for (int i=0;i<5;i++) {
        mat.push_back(vector<int>());
        for (int j=0;j<5;j++) {
            cin >> x;
            mat[i].push_back(x);
        }
    }
    cin >> k;
    Solution s;
    s.kWeakestRows(mat, k);
    return 0;
}