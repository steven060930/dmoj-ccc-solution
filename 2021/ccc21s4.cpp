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

const int mxN=2e5+5;

int n, w, d, st;
int sub[mxN],		// subway
	dp[mxN],		// depth
	id[mxN];

multiset<pair<int, int>> ms; // mpr(time, sub[i]);
vt<vt<int>> adj;

void bfs(int src, int n) {
	memset(dp, 0x3f, sizeof (dp)); dp[src]=0;
	queue<int> q; q.push(src);
	while (sz(q)) {
		int cur=q.front(); q.pop();
		for (auto &E: adj[cur]) {
			if (dp[E] > dp[cur] + 1) {
				dp[E] = dp[cur] + 1;
				q.push(E);
			}
		}
	}
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> n >> w >> d;
	adj.resize(n);
	for (int i=0, A, B; i<w; i++) {
		cin >> A >> B;
		adj[--B].pb(--A);
	}

	for (int i=0; i<n; i++) {
		cin >> sub[i];
		id[--sub[i]] = i;
	}

	bfs(n-1, n);

	for (int i=0; i<n; i++)
		ms.insert(mpr(id[i]+dp[i], i));

	for (int i=0, x, y; i<d; i++) {
		cin >> x >> y; --x; --y;
		ms.erase(mpr(id[sub[x]]+dp[sub[x]], sub[x]));
		ms.erase(mpr(id[sub[y]]+dp[sub[y]], sub[y]));
		swap(id[sub[x]], id[sub[y]]); swap(sub[x], sub[y]);

		ms.insert(mpr(id[sub[x]]+dp[sub[x]], sub[x]));
		ms.insert(mpr(id[sub[y]]+dp[sub[y]], sub[y]));

		cout << ms.begin()->fi << '\n';
	}
}
