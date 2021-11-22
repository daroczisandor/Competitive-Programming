#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        ll q = a / m;
        ll s = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = s;
        s = y;

        // Update y and x
        y = x - q * y;
        x = s;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

const int mxN = 1e6 + 2;
const ll M = 1e9 + 7;

int t,n,k;
vector<int> edge_list[mxN];
bool visited[mxN];
vector<int> node_seq;
int pos[mxN];
int pos_count;

int S[mxN];

void bfs(int node) {
    node_seq.push_back(node);
    pos[node] = pos_count;
    pos_count++;
    visited[node] = true;
    for (int v : edge_list[node]) {
        if (!visited[v]) {
            bfs(v);
        }
    }
}

int main()
{

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for (int i = 0; i<n-1; i++) {
            visited[i] = false;
            S[i] = 0;
            pos[i] = 0;
            int u,v;
            cin >> u >> v;
            u--; v--;
            edge_list[u].push_back(v);
            edge_list[v].push_back(u);
        }
        visited[n-1] = false;
        node_seq.clear();
        pos_count = 0;

        //cout << "Yes";

        bfs(0);

//        cout << "Yes";
//
//        for (int v : node_seq) {
//            cout << v << "\n";
//        }

        for (int i = n-1; i>=0; i--) {
            int u = node_seq[i];
            S[u] = 1;
            for (int v : edge_list[u]) {
                if (pos[u] < pos[v]) {
                    S[u] += S[v];
                }
            }
        }

//        for (int i = 0; i<n; i++) {
//            cout << i << " " << S[i] << "\n";
//        }

        int u = 0;
        int u2 = -1;
        bool ok = true;
        while(ok) {
            ok = false;
            for (int v : edge_list[u]) {
                if (pos[v] > pos[u] && S[v] > n/2) {
                    u = v;
                    ok = true;
                    break;
                } else if (pos[v] > pos[u] && n%2 == 0 && S[v] == n/2) {
                    u2 = v;
                    break;
                }
            }
        }

        //cout << u << "\n";

//        if (k==2) {
//            int mxind = -1;
//            int mx = 0;
//            for (int v : edge_list[u]) {
//                if (S[v] > mx || (S[v] == mx && v > mxind)) {
//                    mx = S[v];
//                    mxind = v;
//                    cout << "S: " << S[v] << " v: " << v << "\n";
//                }
//            }
//            u = mxind;
//        }

//        cout << u << "\n";

        pos_count = 0;
        node_seq.clear();
        for (int i = 0; i<n; i++) {
            visited[i] = false;
        }

        bfs(u);

        for (int i = n-1; i>=0; i--) {
            int w = node_seq[i];
            S[w] = 1;
            for (int v : edge_list[w]) {
                if (pos[w] < pos[v]) {
                    S[w] += S[v];
                }
            }
        }

        if (u2 >= 0 && k==1) {
            u = max(u,u2);
        } else if (u2 >= 0 && k==2) {
            u = min(u,u2);
        } else if (k==2) {
            int mxind = -1;
            int mx = 0;
            for (int v : edge_list[u]) {
                if (S[v] > mx || (S[v] == mx && v > mxind)) {
                    mx = S[v];
                    mxind = v;
//                    cout << "S: " << S[v] << " v: " << v << "\n";
                }
            }
            u = mxind;

            S[u] = n-S[u];
        }
        ll m = M;

        ll prod = 1;
        for (int i = 0; i<n; i++) {
            prod = (M + prod*S[i])%M;
        }
//        cout << "prod: " << prod << "\n";
        ll q = modInverse(prod, m);
//        cout << "q: " << q << "\n";

        ll fact = 1;
        for (int i = 2; i<=n; i++) {
            fact = (M + fact*i)%M;
        }
//        cout << "fact: " << fact << "\n";

        //cout << "prod: " << prod << " q: " << q << " fact: " << fact << "\n";

        ll ans = (M + fact*q)%M;

        cout << u+1 << " " << ans << "\n";

        for (int i = 0; i<n; i++) {
            edge_list[i].clear();
        }

    }

    return 0;
}
