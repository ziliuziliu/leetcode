#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
class MKAverage {
public:
    multiset<int> minK, maxK, medium;
    int *q, total, sum[3], pos, *base;
    int m, k;
    MKAverage(int m, int k):m(m),k(k) {
        q = new int[m+1];
        base = new int[m+1];
        total = sum[0] = sum[1] = sum[2] = 0;
        pos = m-1;
    }
    
    void fillIntoSet() {
        sort(base, base+m);
        for (int i=0;i<k;i++) {
            minK.insert(base[i]); sum[0] += base[i];
            maxK.insert(base[m-1-i]); sum[2] += base[m-1-i];
        }
        for (int i=k;i<m-k;i++) {
            medium.insert(base[i]);
            sum[1] += base[i];
        }
    }

    void updateToSet(int mode, int type, int num) {
        if (type == 0) {
            if (mode == 1) minK.insert(num);
            else {
                auto it = minK.find(num);
                minK.erase(it);
            }
        }
        else if (type == 1) {
            if (mode == 1) medium.insert(num);
            else {
                auto it = medium.find(num);
                medium.erase(it);
            }
        }
        else {
            if (mode == 1) maxK.insert(num);
            else {
                auto it = maxK.find(num);
                maxK.erase(it);
            }
        }
        sum[type] += mode*num;
    }

    void addElement(int num) {
        if (total < m)
            q[total] = base[total] = num;
        else {
            pos = (pos+1)%m;
            if (q[pos] <= *minK.rbegin()) {
                updateToSet(-1, 0, q[pos]);
                if (num > *medium.begin()) {
                    updateToSet(1, 0, *medium.begin());
                    updateToSet(-1, 1, *medium.begin());
                    if (num <= *maxK.begin()) updateToSet(1, 1, num);
                    else {
                        updateToSet(1, 1, *maxK.begin());
                        updateToSet(-1, 2, *maxK.begin());
                        updateToSet(1, 2, num);
                    }
                }
                else updateToSet(1, 0, num);
            }
            else if (q[pos] <= *medium.rbegin()) {
                updateToSet(-1, 1, q[pos]);
                if (num > *maxK.begin()) {
                    updateToSet(1, 1, *maxK.begin());
                    updateToSet(-1, 2, *maxK.begin());
                    updateToSet(1, 2, num);
                }
                else if (num < *minK.rbegin()) {
                    updateToSet(1, 1, *minK.rbegin());
                    updateToSet(-1, 0, *minK.rbegin());
                    updateToSet(1, 0, num);
                }
                else updateToSet(1, 1, num);
            }
            else {
                updateToSet(-1, 2, q[pos]);
                if (num < *medium.rbegin()) {
                    updateToSet(1, 2, *medium.rbegin());
                    updateToSet(-1, 1, *medium.rbegin());
                    if (num < *minK.rbegin()) {
                        updateToSet(1, 1, *minK.rbegin());
                        updateToSet(-1, 0, *minK.rbegin());
                        updateToSet(1, 0, num);
                    }
                    else updateToSet(1, 1, num);
                }
                else updateToSet(1, 2, num);
            }
            q[pos] = num;
        }
        total++;
        if (total == m) fillIntoSet();
    }
    
    int calculateMKAverage() {
        return (total >= m) ? sum[1] / medium.size() : -1;
    }
};

int main() {
    MKAverage obj = MKAverage(3, 1); 
    obj.addElement(3);        
    obj.addElement(1);        
    cout << obj.calculateMKAverage() << endl; 
    obj.addElement(10);       
    cout << obj.calculateMKAverage() << endl;                                         
    obj.addElement(5);       
    obj.addElement(5);        
    obj.addElement(5);       
    cout << obj.calculateMKAverage() << endl; 
    return 0;
}