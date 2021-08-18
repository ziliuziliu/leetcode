#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int bitcount(int x) {
        int ret = 0;
        while (x) {
            ret++;
            x >>= 1;
        }
        return ret;
    }

    vector<int> pathInZigZagTree(int label) {
        int c = bitcount(label);
        if (!(c&1)) label = (1<<(c-1)) + (1<<c) - 1 - label;
        vector<int> ans;
        while (label) {
            ans.push_back(label);
            label >>= 1;
        }
        for (int i=0;i<ans.size()/2;i++) swap(ans[i], ans[ans.size()-1-i]);
        for (int i=0;i<ans.size();i++)
            if (i&1) 
                ans[i] = (1<<i) + (1<<(i+1)) - 1 - ans[i];
        return ans;
    }
};
int main() {
    int label; Solution s;
    cin >> label;
    s.pathInZigZagTree(label);
    return 0;
}