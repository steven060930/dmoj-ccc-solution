#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL) -> sync_with_stdio(0);
    int row, col, k, cnt = 0;
    cin >> row >> col >> k;
    vector<int> r(row+2), c(col+2);
    for (int i = 0; i < k; i++) {
        char tmp; int num;
        cin >> tmp;
        if (tmp == 'R') {
            cin >> num;
            r[num-1] ^= 1;
        }
        else {
            cin >> num;
            c[num-1] ^= 1;
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cnt += r[i] ^c[j];
        }
    }
    cout << cnt << '\n';
    return 0;
}
