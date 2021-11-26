#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt1=0, cnt2=0; cin >> n; string s; cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') cnt1++;
        else cnt2++;
    }
    if (cnt1 == cnt2) cout << "Tie\n";
    else if (cnt1 > cnt2) cout << "A\n";
    else cout << "B\n";
}
