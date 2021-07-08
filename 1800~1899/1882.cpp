#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:

    struct event {
        int t, id;
        event(int t, int id):t(t),id(id) {}
        bool operator < (const event &e) const {
            return this->t > e.t;
        }
    };
    struct server {
        int id, w;
        server(int id, int w):id(id),w(w) {}
        bool operator < (const server &s) const {
            if (this->w != s.w) return this->w > s.w;
            return this->id > s.id;
        }
    };
    priority_queue<event> event_q;
    priority_queue<server> server_q;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        for (int i=0;i<n;i++)
            server_q.push(server(i, servers[i]));
        vector<int> ans;
        for (int i=0;i<m;i++) ans.push_back(0);
        int t = 0, pos = 0;
        while (t < m) {
            while (event_q.size()) {
                event e = event_q.top();
                if (e.t != t) break;
                server_q.push(server(e.id, servers[e.id]));
                event_q.pop();
            }
            while (pos <= t && server_q.size()) {
                server s = server_q.top();
                server_q.pop();
                ans[pos] = s.id;
                event_q.push(event(t + tasks[pos], s.id));
                pos++;
            }
            t++;
        }
        while (pos < m) {
            t = event_q.top().t;
            while (event_q.size()) {
                if (event_q.top().t != t) break;
                event e = event_q.top();
                event_q.pop();
                server_q.push(server(e.id, servers[e.id]));
            }
            while (pos < m && server_q.size()) {
                server s = server_q.top();
                server_q.pop();
                ans[pos] = s.id;
                event_q.push(event(t + tasks[pos], s.id));
                pos++;
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> servers, tasks;
    int x;
    for (int i=0;i<3;i++) {
        cin >> x;
        servers.push_back(x);
    }
    for (int i=0;i<6;i++) {
        cin >> x;
        tasks.push_back(x);
    }
    s.assignTasks(servers, tasks);
    return 0;
}