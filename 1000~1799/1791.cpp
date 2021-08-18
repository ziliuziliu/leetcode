#include<cstdio>
#include<iostream>
using namespace std;
class Solution {
public:
    int findCenter(int edges[20][2]) {
        return (edges[0][0] != edges[1][0]) && (edges[0][0] != edges[1][1]) ? edges[0][1] : edges[0][0];
    }
};
int main() {
    Solution s;
    int edges[20][2];
    for (int i=0;i<4;i++)
        for (int j=0;j<2;j++)
            cin >> edges[i][j];
    cout << s.findCenter(edges);
}