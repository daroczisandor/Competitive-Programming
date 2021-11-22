#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>

#define ll long long

using namespace std;

int steps(string s, int layer) {
    int m = s.size();
    if (m==1) {
        char& c = s[0];
        if ((int)c == layer) {
            return 0;
        }
        return 1;
    }
    string prefix = s.substr(0,m/2);
    string suffix = s.substr(m/2,m/2);
    int prefix_value = 0;
    int suffix_value = 0;
    for (int i = 0; i<m/2; i++) {
        if ((int)s[i]!=layer) prefix_value++;
    }
    for (int i = m/2; i<m; i++) {
        if ((int)s[i]!=layer) suffix_value++;
    }
    return min((prefix_value + steps(suffix, layer+1)), (suffix_value + steps(prefix, layer+1)));
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << steps(s,97) << "\n";
    }
    return 0;
}
