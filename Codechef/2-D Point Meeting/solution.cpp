#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int root(int k) {
    int sq = floor(sqrt((float)(1+8*k)));
    return (1+sq)/2;
}

bool on_line(ll x1, ll y1, ll x2, ll y2, int dir) {
    if (dir == 1) return (y1 == y2);
    if (dir == 2) return (x1 == x2);
    if (dir == 3) return (x2-x1 == y2-y1);
    if (dir == 4) return (x1+y1 == x2+y2);
}

pair<ll,ll> intersection(ll x1, ll y1, int dir1, ll x2, ll y2, int dir2) {

    ll p1, p2, q1, q2, r1, r2;

    switch(dir1) {
        case 1:
            p1 = 0; q1 = 1;
            break;
        case 2:
            p1 = 1; q1 = 0;
            break;
        case 3:
            p1 = 1; q1 = -1;
            break;
        case 4:
            p1 = 1; q1 = 1;
    }

    switch(dir2) {
        case 1:
            p2 = 0; q2 = 1;
            break;
        case 2:
            p2 = 1; q2 = 0;
            break;
        case 3:
            p2 = 1; q2 = -1;
            break;
        case 4:
            p2 = 1; q2 = 1;
    }

    r1 = p1*x1 + q1*y1;
    r2 = p2*x2 + q2*y2;

    ll x = (q2*r1 - q1*r2)/(p1*q2 - p2*q1);
    ll y = (p1*r2 - p2*r1)/(p1*q2 - p2*q1);

    return {x,y};

}

int main()
{

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

//        auto p = intersection(0,0,3,4,2,1);
//        cout << "int: " << p.first << " " << p.second << "\n";

        map<pair<pair<ll,ll>, int>, set<pair<ll,ll>>> line_to_normal_points;
        map<pair<pair<ll,ll>, int>, set<pair<ll,ll>>> line_to_all_points;
        map<pair<ll,ll>, int> scores;
        set<pair<ll,ll>> points;
        vector<pair<pair<ll,ll>, int>> lines;

        ll x[n], y[n];
        for (int i = 0; i<n; i++) {
            int c;
            cin >> c;
            x[i] = 2*c;
        }
        for (int i = 0; i<n; i++) {
            int c;
            cin >> c;
            y[i] = 2*c;
        }

        for (int i = 0; i<n; i++) {
            scores[{x[i], y[i]}]++;
            scores[{x[i], y[i]}]++;
            points.insert({x[i],y[i]});
        }

        for (int i = 0; i<n; i++) {
            for (int dir = 1; dir <= 4; dir++) {
                ll x1 = x[i];
                ll y1 = y[i];
                bool ok = true;
                for (auto line : lines) {
                    int dir2 = line.second;
                    auto p = line.first;
                    ll x2 = p.first;
                    ll y2 = p.second;

                    if (dir == dir2 && on_line(x1, y1, x2, y2, dir)) {
                        ok = false;
                        break;
                    }

                }

                if (ok) {
                    lines.push_back({{x1,y1},dir});
                }
            }
        }

        int line_len = lines.size();
//        cout << "line_len: " << line_len << "\n";
//        for (auto line : lines) {
//            auto p = line.first;
//            ll x1 = p.first;
//            ll y1 = p.second;
//
//            cout << "line: " << x1 << " " << y1 << " " << line.second << "\n";
//
//        }

        for (int i = 0; i<line_len-1; i++) {

            auto line1 = lines[i];
            auto p1 = line1.first;
            ll x1 = p1.first;
            ll y1 = p1.second;
            int dir1 = line1.second;

            for (int j = i+1; j<line_len; j++) {

                auto line2 = lines[j];
                auto p2 = line2.first;
                ll x2 = p2.first;
                ll y2 = p2.second;
                int dir2 = line2.second;

                if (dir1 == dir2) continue;
                auto p = intersection(x1, y1, dir1, x2, y2, dir2);
                ll x0 = p.first;
                ll y0 = p.second;

//                cout << "intersection: " << x0 << " " << y0 << "\n";
//                cout << "line1: " << x1 << " " << y1 << " " << dir1 << "\n";
//                cout << "line2: " << x2 << " " << y2 << " " << dir2 << "\n";

                line_to_all_points[line1].insert({x0, y0});
                line_to_all_points[line2].insert({x0, y0});

            }
        }

        for (auto line : lines) {
            auto p = line.first;
            ll x1 = p.first;
            ll y1 = p.second;
            int dir = line.second;

            for (int j = 0; j<n; j++) {
                ll x2 = x[j];
                ll y2 = y[j];

                if (on_line(x1, y1, x2, y2, dir)) {
                    line_to_all_points[{{x1, y1}, dir}].insert({x2, y2});
                    line_to_normal_points[{{x1, y1}, dir}].insert({x2, y2});
                }

            }

        }

//        for (auto it = line_to_all_points.begin(); it != line_to_all_points.end(); ++it) {
//
//            auto line = (it->first);
//            auto p = line.first;
//            int dir = line.second;
//            auto s = (it->second);
//
//            cout << "line_to_all_points: \n";
//
//            cout << "line: " << p.first << " " << p.second << " " << dir << "\n";
//            cout << "points: \n";
//            for (auto elem : s) {
//                cout << elem.first << " " << elem.second << "\n";
//            }
//
//
//        }

//        for (auto it = line_to_normal_points.begin(); it != line_to_normal_points.end(); ++it) {
//
//            auto line = (it->first);
//            auto p = line.first;
//            int dir = line.second;
//            auto s = (it->second);
//
//            cout << "line_to_normal_points: \n";
//
//            cout << "line: " << p.first << " " << p.second << " " << dir << "\n";
//            cout << "points: \n";
//            for (auto elem : s) {
//                cout << elem.first << " " << elem.second << "\n";
//            }
//
//
//        }

        for (auto it = line_to_normal_points.begin(); it != line_to_normal_points.end(); ++it) {

            auto line = (it->first);
            auto s0 = (it->second);
            int sz = s0.size();

            //cout << "line: " << (line.first).first << " " << (line.first).second << " " << line.second << " size: " << sz << "\n";

            auto s = line_to_all_points[line];
            for (auto it2 = s.begin(); it2 != s.end(); ++it2) {

                auto p = *it2;

                scores[p] += sz;

                if (points.find(p) != points.end()) {
                    scores[p]--;
                }

//                if (p.first == 0 && p.second == 1) cout << "pair 0 1: line: " << (line.first).first << " " << (line.first).second << " " << line.second << " size: " << sz << "\n";

            }

        }

        int mx = 0;
        for (auto it = scores.begin(); it != scores.end(); ++it) {

            int val = (it->second);
//            cout << "point: " << (it->first).first << " " << (it->first).second << " val: " << val << "\n";
            if (val > mx) mx = val;

        }

        cout << 2*n-mx << "\n";




    }

    return 0;
}
