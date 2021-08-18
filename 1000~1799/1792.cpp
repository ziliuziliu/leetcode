#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
class Solution {
public:
    struct cl {
        int pass, total;
        double rate;
        cl(int pass, int total, double rate): pass(pass), total(total), rate(rate) {}
        friend bool operator < (cl c1, cl c2) {
            return c1.rate < c2.rate;
        }
    };
    double maxAverageRatio(int classes[20][3], int extraStudents) {
        int size = 3;
        priority_queue<cl> q;
        for (int i=0;i<size;i++) {
            int pass = classes[i][0], total = classes[i][1];
            q.push(cl(pass, total, (double)(total-pass)/(total*(total+1))));
        }
        for (int i=0;i<extraStudents;i++) {
            cl c = q.top(); q.pop();
            c.pass += 1; c.total += 1;
            q.push(cl(c.pass, c.total, (double)(c.total-c.pass)/(c.total*(c.total+1))));
        }
        double ans = 0;
        for (int i=0;i<size;i++)
        {
            cl c = q.top(); q.pop();
            ans += (double)c.pass / c.total;
        }
        return ans / size;
    }
};
int main() {
	Solution s;
	int classes[20][3], extra;
	for (int i=0;i<3;i++)
		for (int j=0;j<2;j++)
			cin >> classes[i][j];
    cin >> extra;
	cout << s.maxAverageRatio(classes, extra) << endl;
    return 0;
}
