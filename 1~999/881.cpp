#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1, ans = 0;
        while (left < right) {
            while (left < right && people[left] + people[right] > limit) { right--; ans++; }
            left++; right--; ans++;
        }
        if (left == right) ans++;
        return ans;
    }
};
int main() {
    int x, limit; vector<int> people;
    for (int i=0;i<2;i++) {
        cin >> x;
        people.push_back(x);
    }
    cin >> limit;
    Solution s;
    cout << s.numRescueBoats(people, limit) << endl;
    return 0;
}