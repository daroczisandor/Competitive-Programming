#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>

#define ll long long

using namespace std;

bool kis(pair<int,int> p1, pair<int,int> p2) {
    return (p1.second > p2.second);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        int r[n];
        for (int i = 0; i<n; i++) {
            cin >> r[i];
        }
        int c[n][m];
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                cin >> c[i][j];
            }
        }
        int mxpoint[n] = {0};
        int mxpointind[n] = {0};
        int mnranking[n];
        int mnrankingind[n] = {0};
        for (int i = 0; i<n; i++) {
            mnranking[i] = 1000;
        }
        for (int j = 0; j<m; j++) {
            for (int i = 0; i<n; i++) {
                r[i] += c[i][j];
            }
            pair<int,int> p[n];
            int ranking[n];
            for (int i = 0; i<n; i++) {
                p[i] = {i,r[i]};
            }
            sort(p,p+n,kis);
            int prev_score = p[0].second;
            int prev_person = p[0].first;
            ranking[prev_person] = 1;
            for (int i = 1; i<n; i++) {
                int score = p[i].second;
                int person = p[i].first;
                if (score == prev_score) {
                    ranking[person] = ranking[prev_person];
                } else {
                    ranking[person] = i+1;
                    prev_person = person;
                    prev_score = score;
                }
            }
            for (int i = 0; i<n; i++) {
                if (mxpoint[i]<r[i]) {
                    mxpoint[i] = r[i];
                    mxpointind[i] = j;
                }
                if (mnranking[i]>ranking[i]) {
                    mnranking[i] = ranking[i];
                    mnrankingind[i] = j;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i<n; i++) {
            if (mnrankingind[i] != mxpointind[i]) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
