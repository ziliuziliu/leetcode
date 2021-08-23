#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
class TimeMap {
public:

    struct val {
        string value;
        int timestamp;
        val(string value, int timestamp):value(value),timestamp(timestamp) {}
        bool operator < (const val &x) const {
            return this->timestamp < x.timestamp;
        }
    };
    map<string, vector<val>> mp;

    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        val v = val(value, timestamp);
        if (!mp.count(key)) mp[key] = vector<val>();
        mp[key].push_back(v);
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        vector<val>::iterator it = upper_bound(mp[key].begin(), mp[key].end(), val("", timestamp));
        if (it == mp[key].begin()) return "";
        it--;
        return it->value;
    }
};
int main() {
    return 0;
}