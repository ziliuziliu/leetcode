#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    struct event {
        int id, x, h, flag;
        event(int id, int x, int h, int flag):id(id),x(x),h(h),flag(flag) {}
        bool operator < (const event &x) const {
            return this->x < x.x;
        }
    };

    struct building {
        int id, h;
        building(int id, int h):id(id),h(h) {}
        bool operator < (const building &x) const {
            if (this->h != x.h) return this->h > x.h;
            return this->id < x.id;
        }
    };

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<event> events;
        set<building> s;
        vector<vector<int>> ans;
        int n = buildings.size();
        for (int i=0;i<n;i++) {
            int left = buildings[i][0], right = buildings[i][1], height = buildings[i][2];
            events.push_back(event(i, left, height, 1));
            events.push_back(event(i, right, height, -1));
        }
        sort(events.begin(), events.end());
        int pos = 0, preH = -1;
        while (pos < 2*n) {
            int nowX = events[pos].x;
            while (pos < 2*n) {
                event nowE = events[pos];
                if (nowE.x != nowX) break;
                if (nowE.flag == 1) s.insert(building(nowE.id, nowE.h));
                else s.erase(building(nowE.id, nowE.h));
                pos++;
            }
            if (preH != s.begin() -> h) {
                preH = s.begin() -> h;
                vector<int> ret;
                ret.push_back(nowX); ret.push_back(preH);
                ans.push_back(ret);
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> buildings;
    int x;
    for (int i=0;i<5;i++) {
        buildings.push_back(vector<int>());
        for (int j=0;j<3;j++) {
            cin >> x;
            buildings[i].push_back(x);
        }
    }
    Solution s;
    s.getSkyline(buildings);
    return 0;
}