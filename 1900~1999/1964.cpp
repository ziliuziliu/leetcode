#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    struct event {
        int val, pos;
        event(int val, int pos):val(val),pos(pos) {}
        bool operator < (const event &e) {
            if (this->val != e.val) return this->val < e.val;
            return this->pos < e.pos;
        }
    };

    int ret[100050], lon[100050], n;
    int lowbit(int x) {return x&(-x);}
    void insert(int pos, int val) {
        for (int i=pos;i<=n;i+=lowbit(i)) ret[i] = max(ret[i], val);
    }
    int query(int pos) {
        int ans = 0;
        for (int i=pos;i>=1;i-=lowbit(i)) ans = max(ans, ret[i]);
        return ans;
    }
    
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<event> v; n = obstacles.size();
        for (int i=0;i<obstacles.size();i++) v.push_back(event(obstacles[i], i+1));
        sort(v.begin(), v.end());
        for (int i=0;i<v.size();i++) {
            int val = v[i].val, pos = v[i].pos;
            lon[pos] = query(pos) + 1;
            insert(pos, lon[pos]);
        }
        vector<int> ans;
        for (int i=1;i<=n;i++) ans.push_back(lon[i]);
        return ans;
    }
};
int main() {
    int x;
    vector<int> obstacles;
    Solution s;
    for (int i=0;i<4;i++) {
        cin >> x;
        obstacles.push_back(x);
    }
    s.longestObstacleCourseAtEachPosition(obstacles);
    return 0;
}