#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int ans = 0;
        for (int i=0;i<triplets.size();i++) {
            int bits = 0, available = 1;
            for (int j=0;j<3;j++) {
                if (triplets[i][j] == target[j]) bits += (1<<j);
                else if (triplets[i][j] > target[j]) available = 0;
            }
            if (available) ans |= bits;
            if (ans == 7) return true;
        }
        return false;
    }
};
int main() {
    int x;
    vector<vector<int>> triplets;
    vector<int> target;
    for (int i=0;i<3;i++) {
        triplets.push_back(vector<int>());
        for (int j=0;j<3;j++) {
            cin >> x;
            triplets[i].push_back(x);
        }
    }
    for (int i=0;i<3;i++) {
        cin >> x;
        target.push_back(x);
    }
}