#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
class Solution {
public:

    static bool cmp(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        map<char, int> mp;
        for (int i=0;i<s.length();i++) {
            if (mp.count(s[i]) == 0) mp[s[i]] = 0;
            mp[s[i]]++;
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);
        string result;
        for (int i=0;i<v.size();i++) result.append(v[i].second, v[i].first);
        return result;
    }
};
int main() {
    string x;
    cin >> x;
    Solution s;
    cout << s.frequencySort(x) << endl;
    return 0;
}