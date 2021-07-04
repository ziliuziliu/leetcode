#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
class Solution {
public:
    
    int regular(int h1, int h2, int m1, int m2) {
        return (60-m1)/15 + m2/15 + (h2-h1-1)*4;
    }
    
    int numberOfRounds(string startTime, string finishTime) {
        int h1 = atoi(startTime.substr(0, 2).c_str()), h2 = atoi(finishTime.substr(0, 2).c_str());
        int m1 = atoi(startTime.substr(3, 2).c_str()), m2 = atoi(finishTime.substr(3, 2).c_str());
        if (h1 == h2) {
            if (m1 < m2) return max(0, m2/15 - (int)ceil((double)m1/15));
            else if (m1 == m2) return 0;
            else return regular(h1, h2+24, m1, m2);
        }
        else if (h2 == h1+1)
            return m2/15 + (60-m1)/15;
        else if (h2 < h1)
            return regular(h1, h2+24, m1, m2);
        else 
            return regular(h1, h2, m1, m2);
    }
};
int main() {
    string startTime, finishTime;
    cin >> startTime >> finishTime;
    Solution s;
    cout << s.numberOfRounds(startTime, finishTime) << endl;
    return 0;
}