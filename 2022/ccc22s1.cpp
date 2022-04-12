#include "bits/stdc++.h"
using namespace std;

int main() {
    int n; cin >> n; int ret = n%5 == 0? 0 : 5-n%5;
    if (n-ret*4 < 0) { cout << 0 << '\n'; return 0; }
    cout << 1 + (int)((n-ret*4)/5/4) << '\n';
}
