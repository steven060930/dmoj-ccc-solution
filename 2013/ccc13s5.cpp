#include "bits/stdc++.h"
using namespace std;

#define vt vector
#define mpr make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) (int)(x.size())

typedef long long ll;	typedef long double ld;

int n,
	ans;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);

	cin >> n;
	while (1) {
		if (n == 1)
			goto print;

		loop:
		for (int i=2; i<=n+2; i++) {
			if (!(n%i)) {
				int d=n/i;
				ans += (n-d) / d;
				n -= d;
				goto loop;
			}
		}

	}

    print: cout << ans << '\n';
}
