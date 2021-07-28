#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    struct event {
        int id, val;
        event(int id, int val):id(id),val(val) {}
        bool operator < (const event &e) const {
            if (this->val != e.val) return this->val < e.val;
            return this->id > e.id;
        }
    };

    int dp[100050] = {0}, n;
    
    int lowbit(int x) {return x&(-x);}
    int query(int x) {
        int mx = 0;
        for (int i=x;i;i-=lowbit(i)) mx = max(mx, dp[i]);
        return mx;
    }
    void update(int x, int val) {
        for (int i=x;i<=n;i+=lowbit(i)) dp[i] = max(dp[i], val);
    }

    int minOperations(vector<int>& target, vector<int>& arr) {
        map<int, int> mp;
        vector<event> v;
        n = arr.size();
        int ans = 0, ret;
        for (int i=0;i<target.size();i++) mp[target[i]] = i;
        for (int i=0;i<arr.size();i++)
            if (mp.count(arr[i])) 
                v.push_back(event(i+1, mp[arr[i]]));
        sort(v.begin(), v.end());
        for (int i=0;i<v.size();i++) {
            ret = query(v[i].id);
            ans = max(ans, ret+1);
            update(v[i].id, ret+1);
        }
        return target.size() - ans;
    }
};
int main() {
    vector<int> target, arr;
    int x;
    for (int i=0;i<3;i++) {
        cin >> x;
        target.push_back(x);
    }
    for (int i=0;i<5;i++) {
        cin >> x;
        arr.push_back(x);
    }
    Solution s;
    cout << s.minOperations(target, arr) << endl;
    return 0;
}