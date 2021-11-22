#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int flips[15] = {1, 2, 1, 3, 1, 2, 1, 4, 1, 3, 1, 2, 1, 3, 1};
int two_flips[3] = {1, 2, 1};

int query(int X, int Y) {
    cout << 1 << " " << X+1 << " " << Y+1 << "\n" << flush;
    int z;
    cin >> z;
    return z;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,q,k;
        cin >> n >> q >> k;
        int squares = k;
        for (int i = 0; i<n-1; i+=2) {
            for (int j = 0; j<n-1; j+=2) {
                int ind = 0;
                while(ind < 15) {
                    int a = flips[ind];
                    int x,y;
                    if (a==1) {
                        x = i; y=j;
                    }
                    if (a==2) {
                        x = i; y=j+1;
                    }
                    if (a==3) {
                        x = i+1; y=j;
                    }
                    if (a==4) {
                        x = i+1; y=j+1;
                    }
                    int central = int(i>0 && j>0);
                    //cout << central << "\n";
                    int z = query(x,y);
                    if (z==-1) exit(0);
                    if (a==1 && z==squares+1+central) {
                        squares = z;
                        break;
                    }
                    if (a==1 && z==squares-1-central) {
                        //cout << "hey" << "\n";
                        z = query(i,j);
                        if (z==-1) exit(0);
                        squares = z;
                        break;
                    }
                    squares = z;
                    ind++;
                }
            }
        }

        if (n%2==0) {
            cout << 2 << "\n";
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<n; j++) {
                    cout << (i+j)%2 << " ";
                }
                cout << "\n";
            }
            int z;
            cin >> z;
            if (z==-1) exit(0);
            continue;
        }

        //step 1
        int i = n-2;
        for (int j = 0; j<n-1; j++) {
            int z = query(i,j);
            if (z==-1) exit(0);
        }
        int l = n-2;
        for (int k = 0; k<n-2; k++) {
            int z = query(k,l);
            if (z==-1) exit(0);
            squares = z;
        }

        //step2
        i = n-1;
        for (int j = 0; j<n-1; j+=2) {
            int ind = 0;
            while(ind<3) {
                int a = two_flips[ind];
                int x,y;
                if (a==1) {
                    x = i; y = j;
                }
                if (a==2) {
                    x = i; y = j+1;
                }
                int z = query(x,y);
                if (z==-1) exit(0);
                if (z>squares) {
                    squares = z;
                    break;
                }
                if (z<squares) {
                    z = query(x,y);
                    if (z==-1) exit(0);
                    squares = z;
                    break;
                }
                ind++;
            }
        }

        //step3
        l = n-1;
        for (int k = 0; k<n-1; k+=2) {
            int ind = 0;
            while(ind<3) {
                int a = two_flips[ind];
                int x,y;
                if (a==1) {
                    x = k; y = l;
                }
                if (a==2) {
                    x = k+1; y = l;
                }
                int z = query(x,y);
                if (z==-1) exit(0);
                if (z>squares) {
                    squares = z;
                    break;
                }
                if (z<squares) {
                    z = query(x,y);
                    if (z==-1) exit(0);
                    squares = z;
                    break;
                }
                ind++;
            }
        }

        //step4
        int z = query(n-2,n-1);
        if (z==-1) exit(0);
        z = query(n-2,n-2);
        if (z==-1) exit(0);
        z = query(n-1,n-2);
        if (z==-1) exit(0);
        squares = z;

        //step5
        z = query(n-1,n-1);
        if (z==-1) exit(0);
        if (z<squares) {
            z = query(n-1,n-1);
            if (z==-1) exit(0);
        }

        cout << 2 << "\n";
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                int a = i + j + int(i>=n-2 || j>=n-2) + int(i>=n-2 && j>=n-2);
                a = a%2;
                cout << a << " ";
            }
            cout << "\n";
        }
        cin >> z;
        if (z==-1) exit(0);

    }

    return 0;
}
