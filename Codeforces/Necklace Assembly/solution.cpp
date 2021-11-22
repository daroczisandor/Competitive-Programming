#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int BIG = 2*10e9;

int main()
{

    int t;
    cin >> t;
    while(t--) {

        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int countLetters[30] = {0};
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c < 'a' || c > 'z') continue;
            countLetters[c-'a'] += 1;
        }
        sort(countLetters, countLetters+30);
        int a[30];
        int N;
        int c=0;
        while(countLetters[c]==0) {
            c++;
        }
        int i = 0;
        while(c+i<30) {
            a[i] = countLetters[c+i];
            i++;
        }
        N = 30-c;

        int f[N][n];
        for (int i = 0; i<n; i++) {
            f[0][i] = a[N-1]/(i+1);
        }
        for (int M = 1; M<N; M++) {
            for (int l = 0; l<n; l++) {
                f[M][l] = 0;
                for (int j = 0; j<=l/M; j++) {
                    int val;
                    if (j>0) {
                        val = a[N-M-1]/(j);
                    } else {
                        val = BIG;
                    }
                    f[M][l] = max(f[M][l], min(val, f[M-1][l-j]));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i<n; i++) {
            int l = i+1;
            if (k%l==0) {
                ans = max(ans, l*f[N-1][i]);
            }
        }
        cout << ans << "\n";


    }

    return 0;
}
