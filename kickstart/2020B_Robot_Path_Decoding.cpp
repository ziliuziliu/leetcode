#include<bits/stdc++.h>
using namespace std;
int T, mod = 1e9;
string program;
struct action {
    bool bracket = false;
    long long n, s, w, e;
    action(long long n, long long s, long long w, long long e):n(n), s(s), w(w), e(e) {}
    action(bool bracket):bracket(bracket) {}
};
stack<action> s;
stack<int> param;
int main() {
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        cin >> program;
        for (int i=0;i<program.length();i++) {
            long long nT = 0, sT = 0, wT = 0, eT = 0;
            switch (program[i]) {
                case 'N':
                    s.push(action(1, 0, 0, 0));
                    break;
                case 'S':
                    s.push(action(0, 1, 0, 0));
                    break;
                case 'W':
                    s.push(action(0, 0, 1, 0));
                    break;
                case 'E':
                    s.push(action(0, 0, 0, 1));
                    break;
                case '(':
                    s.push(action(true));
                    break;
                case ')':
                    while (!s.empty()) {
                        action ac = s.top(); s.pop();
                        if (ac.bracket) {
                            int p = param.top(); param.pop();
                            nT = nT * p % mod; sT = sT * p % mod;
                            wT = wT * p % mod; eT = eT * p % mod;
                            break;
                        }
                        nT = (nT + ac.n) % mod; sT = (sT + ac.s) % mod;
                        wT = (wT + ac.w) % mod; eT = (eT + ac.e) % mod;
                    }
                    s.push(action(nT, sT, wT, eT));
                    break;
                default:
                    param.push(program[i] - '0');
                    break;
            }
        }
        long long nT = 0, sT = 0, wT = 0, eT = 0;
        while (!s.empty()) {
            action ac = s.top(); s.pop();
            nT = (nT + ac.n) % mod; sT = (sT + ac.s) % mod;
            wT = (wT + ac.w) % mod; eT = (eT + ac.e) % mod;
        }
        printf("Case #%d: %lld %lld\n", t, (eT - wT + mod) % mod + 1, (sT - nT + mod) % mod + 1);      
    }
    return 0;
}