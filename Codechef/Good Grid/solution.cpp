#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{

    int t;
    cin >> t;
    while(t--) {
        int n,x;
        cin >> n >> x;
        int k = n;
        while(k>0 && x%k != 0) k--;
        if (x > n*k) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }

    return 0;
}
