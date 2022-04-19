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

const int mxN = 403;
int n, lb, rb, psa[mxN], a[mxN], dp[mxN][mxN], ans;

// whatever how they combined, the final size will always be psa[j] - psa[i-1] (j>i)

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);

	memset(dp, 0, sizeof (dp)); memset(psa, 0, sizeof (psa));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		dp[i][i] = x; ans = max(ans, x);
		psa[i] = psa[i-1] + x;
	}


	for (int inv = 1; inv < n; ++inv) {
		//interval
		for (int l = 1, r, lb, hb; l+inv <= n; l++) {
			r = l + inv;
			lb = 1; hb = r;
			while (lb < hb) {
				if (dp[l][lb] && dp[hb][r] && dp[l][lb] == dp[hb][r]) {
					if (lb + 1 == hb) //next to each other
						dp[l][r] = max(dp[l][r], dp[l][lb] + dp[hb][r]);
					if (lb + 1 < hb && dp[lb+1][hb-1]) 
						dp[l][r] = max(dp[l][r], dp[l][lb] + dp[lb+1][hb-1] + dp[hb][r]);

					ans = max(ans, dp[l][r]);
				}

				if (psa[lb] - psa[l-1] == psa[r] - psa[hb-1]) {
					++lb; --hb;
				}
				else if (psa[lb] - psa[l-1] < psa[r] - psa[hb-1])
					lb++;
				else 
					hb--;
			}
		}
	}

	cout << ans << '\n';
}


// 47, 24, 3, 9, 9, 3
//
// 47, 24, 3, 18, 3
//
// 47, 24, 24,
//
// 47, 48
//
// >>> 48
