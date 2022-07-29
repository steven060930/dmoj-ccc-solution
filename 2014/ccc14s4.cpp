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

const int mxN = 1005;
const int MM = 2005;

int n, t;
ll ans, pos[MM][2], psa[MM][MM], tk[MM][MM];
ll a[mxN], b[mxN], c[mxN], d[mxN], val[mxN];
vt<int> idx, idy;

int getx(int a) {
	return lower_bound(all(idx), a) - idx.begin() + 1;
}
int gety(int a) {
	return lower_bound(all(idy), a) - idy.begin() + 1;
}

int cnt;
int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> n >> t;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> val[i];
		idx.pb(a[i]); idx.pb(c[i]);
		idy.pb(b[i]); idy.pb(d[i]);
	}

	sort(all(idx)); idx.erase(unique(all(idx)), idx.end());
	sort(all(idy)); idy.erase(unique(all(idy)), idy.end());

	for (int i=0; i<n; i++) {
		psa[getx(a[i])][gety(b[i])] += val[i];
		psa[getx(a[i])][gety(d[i])] -= val[i];
		psa[getx(c[i])][gety(b[i])] -= val[i];
		psa[getx(c[i])][gety(d[i])] += val[i];
	}

	for (int i=1; i<=sz(idx); i++) {
		for (int j=1; j<=sz(idy); j++) {
			psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
			if (psa[i][j] >= t)
				cnt++;
				//ans += (ll)(idx[i]-idx[i-1])*(idy[i]-idy[i-1]);
		}
	}

	/*
	for (auto x: idx)
		cout << x << ' ';
	cout << '\n';
	for (auto y: idy)
		cout << y << ' ' ;
	cout << '\n';
	*/
	cout << cnt << '\n';
	//cout << ans << '\n';
}
