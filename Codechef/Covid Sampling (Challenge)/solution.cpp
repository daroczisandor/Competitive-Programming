#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <set>
using namespace std;

int t;

void print_out(int a, int b, int c, int d) {
    // r1 c1 r2 c2
    cout << 1 << " " << a << " " << b << " " << c << " " << d << "\n";
}

int main() {
	// your code goes here

	cin >> t;
	while(t--) {

        int n;
        int p;
        cin >> n >> p;
        int row_sums[n], column_sums[n];
        int A[n][n];

        int total_sum;
        print_out(1,1,n,n);
        cin >> total_sum;

        for (int i = 1; i<n+1; i++) {

            int above, below;
            print_out(1,1,i,n);
            cin >> above;
            print_out(i,1,n,n);
            cin >> below;
            row_sums[i-1] = above + below - total_sum;

            int left, right;
            print_out(1,1,n,i);
            cin >> left;
            print_out(1,i,n,n);
            cin >> right;
            column_sums[i-1] = left + right - total_sum;
        }

        for (int i = 1; i<n+1; i++) {
            for (int j = 1; j<n+1; j++) {

                int ul, ur, ll, lr;
                print_out(1,1,i,j);
                cin >> ul;
                print_out(1,j,i,n);
                cin >> ur;
                print_out(i,1,n,j);
                cin >> ll;
                print_out(i,j,n,n);
                cin >> lr;

                int x = (ul + ur + ll + lr -total_sum) - row_sums[i-1] - column_sums[j-1];
                A[i-1][j-1] = x;

            }
        }

        cout << 2 << "\n";
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
        
        int X;
        cin >> X;
        if (X==-1) {
            return 0;
        }

	}


	return 0;
}
