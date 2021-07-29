#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool flag = false;
        for (int i=0;i<num.length();i++) {
            if (num[i]-'0' < change[num[i]-'0'] || (num[i]-'0' == change[num[i]-'0'] && flag)) {
                num[i] = change[num[i]-'0'] + '0';
                flag = true;
            }
            else if (flag) 
                break;
        }
        return num;
    }
};
int main() {
    string num;
    vector<int> change;
    int x;
    Solution s;
    cin >> num;
    for (int i=0;i<10;i++) {
        cin >> x;
        change.push_back(x);
    }
    cout << s.maximumNumber(num, change) << endl;
    return 0;
}