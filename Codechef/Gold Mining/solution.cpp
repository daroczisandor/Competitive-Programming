#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

const int mxN = 1000005;
int a[mxN];

int main()
{

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        double sumA=0, sumB=0;
        for (int i = 0; i<n; i++) {
            double g, a, b;
            cin >> g >> a >> b;
            sumA += g*b/(a+b);
            sumB += g*a/(a+b);

        }
        cout << fixed << setprecision(7) << sumA << ' ' << sumB << '\n';
    }

    return 0;
}
