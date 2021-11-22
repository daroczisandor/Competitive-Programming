#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

const int mxN = 200005;
int t,n;
int a[mxN], b[mxN];

int main()
{

    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> b[i];
        }
        sort(a,a+n);
        sort(b,b+n);

        map<int,int> a_freq;
        map<int,int> b_freq;
        set<int> elements;
        int mini = min(a[0],b[0]);

        for (int i = 0; i<n; i++) {
            a_freq[a[i]]++;
            b_freq[b[i]]++;
            elements.insert(a[i]);
            elements.insert(b[i]);
        }

        int arr[n];
        int l = 0;
        bool ok = true;
        for (int x : elements) {
            int u = a_freq[x];
            int v = b_freq[x];
            if (abs(u-v+2)%2 == 1) {
                ok = false;
                break;
            } else if (u!=v){
                int freq = (abs(u-v))/2;
                for (int j = 0; j<freq; j++) {
                    arr[l] = x;
                    l++;
                }
            }
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        sort(arr, arr+l);
        long long int cost = 0;
        for (int i = 0; i<l/2; i++) {
            cost += min(arr[i], 2*mini);
        }
        cout << cost << "\n";

    }

    return 0;
}
