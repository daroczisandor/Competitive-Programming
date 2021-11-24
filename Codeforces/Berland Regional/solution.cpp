#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int u[n];
        ll s[n];
        for (int i = 0; i<n; i++) {
            cin >> u[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> s[i];
        }

        multiset<int, greater<int>> uni[n];

        for (int i = 0; i<n; i++) {
            uni[u[i]-1].insert(s[i]);
        }

        vector<ll> partial_sums[n];

        for (int i = 0; i<n; i++) {
            ll small_sum = 0;
            partial_sums[i].push_back(0);
            for (int c : uni[i]) {
                small_sum += c;
                partial_sums[i].push_back(small_sum);
            }
        }

        set<int> big_indices;
        for (int i = 0; i<n; i++) {
            if (uni[i].size()>0) big_indices.insert(i);
            //cout << "uni: " << i << " len: " << uni[i].size() << "\n";
        }

        //cout << "Yes";
        for (int k = 1; k<=n; k++) {
            //cout << "Yes";
            set<int> to_remove;
            ll k_sum = 0;
            for (int i : big_indices) {
                //cout << "k: " << k << " i: " << i << "\n";
                int len = uni[i].size();
                if (len == k) to_remove.insert(i);

                int q = len/k;
                int m = len%k;
                int ind = q*k;

                k_sum += partial_sums[i][ind];
            }
            for (int j : to_remove) {
                big_indices.erase(j);
            }

            cout << k_sum << " ";

        }

        cout << "\n";


    }
    return 0;
}
