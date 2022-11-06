#include "bits/stdc++.h"
using namespace std;

#define vt vector
#define mpr make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(s) (int)(s.size())

typedef long long ll;	typedef long double ld;

int n, m, q, dp[101], t[101], cap[101]; 
string name[101];
vector<int> ord;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> m >> q;
	for (int i = 0; i < q; i++) cin >> name[i] >> t[i];

	memset(dp, 0x3f3f3f3f, sizeof (dp)); dp[0] = 0;

	for (int i = 0; i < q+1; i++) {
		int mx = -1;
		for (int j=0; j<m; j++) {
			if (i+j+1 > q) 
				break;
			mx = max(mx, t[i+j]);

			if (dp[i]+mx < dp[i+j+1]) {
				dp[i+j+1] = dp[i]+mx;
				cap[i+j+1]=j+1;
			}
		}
	}

	int id=q, p=-1;
	while (id != 0) {
		ord.pb(cap[id]);
		id -= cap[id];
	}
	
	cout << "Total Time: " << dp[q] << '\n';

	for (int i=sz(ord)-1; i>=0; i--) {
		while (ord[i]--)
			cout<< name[++p] << ' ';
		cout << '\n';
	}
}
