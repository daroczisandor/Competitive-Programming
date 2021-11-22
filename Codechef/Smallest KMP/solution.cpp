#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string s,p;
        cin >> s;
        cin >> p;
        char first = p[0];
        int second_ind = 1;
        while(second_ind < p.length() && p[second_ind]==p[0]) second_ind++;
        char second;
        if (second_ind == p.length()) {
            second = first;
        } else {
            second = p[second_ind];
        }
        map<int,int> smp;
        map<int,int> pmp;
        for (int i = 0; i<s.length(); i++) {
            smp[(int)s[i]]++;
        }
        for (int i = 0; i<p.length(); i++) {
            pmp[(int)p[i]]++;
        }
        string sub;
        int i = 97;
        while(i<first) {
            if (smp[i]-pmp[i] > 0) {
                for (int j = 0; j<smp[i]-pmp[i]; j++) {
                    sub.push_back((char)i);
                }
            }
            i++;
        }
        if (second>=first) {
            if (smp[i]-pmp[i] > 0) {
                for (int j = 0; j<smp[i]-pmp[i]; j++) {
                    sub.push_back((char)i);
                }
            }
            i++;
        }
        sub += p;
        while(i<123) {
            if (smp[i]-pmp[i] > 0) {
                for (int j = 0; j<smp[i]-pmp[i]; j++) {
                    sub.push_back((char)i);
                }
            }
            i++;
        }
        cout << sub << "\n";
    }

    return 0;
}
