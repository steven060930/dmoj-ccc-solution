#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first 
#define se second
#define sz(x) (int)((x).size())
using namespace std;

using pii = pair<int, int>;
using ll = long long;

int n, t, ans; vector<pii> a;

inline bool cmp(pii a, pii b) { return a.fi < b.fi; }

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >>t;
	for (int i=0, x,y ; i< t; i++)
		cin >> x >> y, a.push_back(make_pair(x, y));
	a.push_back(make_pair(0, 0)), a.push_back(make_pair(n+1, n+1)),sort(all(a), cmp);

	for (int i=0; i < sz(a); i++) {
		vector<int> tmp = {0 ,n+1};
		for (int j=i+1; j<sz(a); j++) {
			int mx = -1;
			sort(all(tmp));
			for (int k=1; k<sz(tmp); k++) 
				mx = max(mx, tmp[k] - tmp[k-1] - 1);
			ans = max(ans, min(mx, a[j].fi - a[i].fi - 1));
			tmp.push_back(a[j].se);
		}
	}
	
	cout << ans << '\n';
}
