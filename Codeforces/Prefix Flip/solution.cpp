#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>

#define ll long long

using namespace std;

bool ls(pair<int,int> p1, pair<int,int> p2)
{
    return (p1.first < p2.first);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a,b;
        cin >> a;
        cin >> b;
        int a_ind = 0;
        int a_upper = n-1;
        int b_ind = n-1;
        int p[2*n];
        int k = 0;
        int diff = 0;
        int first_diff = 0;
        while(a_ind < a_upper) {
            if (diff==0) {
                int len = 0;
                int start = a_ind;
                if ((a[a_ind] + diff + first_diff)%2 == b[b_ind]%2) {
                    p[k] = 1;
                    k++;
                    first_diff = 1;
                    continue;
                }
                while(a_ind < a_upper && (((a[a_ind] + b[b_ind] + diff)%2 == 1) || (a_ind==start && (a[a_ind] + b[b_ind] + diff + first_diff)%2 == 1))) {
                    a_ind++;
                    b_ind--;
                    len++;
                }
                diff = 1-diff;
                p[k] = a_upper-start+1;
                k++;
                first_diff = 0;
            } else {
                int len = 0;
                int start = a_upper;
                if ((a[a_upper] + diff + first_diff)%2 == b[b_ind]%2) {
                    p[k] = 1;
                    k++;
                    first_diff = 1;
                    continue;
                }
                while(a_upper > a_ind && (((a[a_upper] + b[b_ind] + diff)%2 == 1) || (a_upper==start && (a[a_upper] + b[b_ind] + diff + first_diff)%2 == 1))) {
                    a_upper--;
                    b_ind--;
                    len++;
                }
                diff = 1-diff;
                p[k] = start+1 - a_ind;
                k++;
                first_diff = 0;
            }
        }
        if ((a[a_ind] + diff + first_diff + 1)%2 == b[b_ind]%2) {
            p[k] = 1;
            k++;
        }
        cout << k;
        for (int i = 0; i<k; i++) {
            cout << " " << p[i];
        }
        cout << "\n";
    }
    return 0;
}
