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

const int mxN = 2e3+1;

struct E{
	int u;
	int d;
	int h;
	bool operator <(const E &x) const { return d > x.d; }
};

//bool cmp(E &a, E &b) { return a.d > b.d; }

int n;
int m;
int k;
int a;
int b;
int ans = 0x3f3f3f3f;
int dis[mxN][201];

vt<vt<E>> adj(mxN);

void dijkstra(int src) {
	priority_queue<E> pq;
	memset(dis, 0x3f3f3f3f, sizeof dis);
	dis[src][0] = 0; pq.push({src, 0, 0});

	while (sz(pq)) {
		auto cur = pq.top(); pq.pop();

		if (dis[cur.u][cur.h] < cur.d)
			continue;

		for (auto e: adj[cur.u]) {
			int h = cur.h + e.h;
			if (h >= k || dis[e.u][h] < cur.d + e.d)
				continue;
			dis[e.u][h] = cur.d + e.d;
			pq.push({e.u, dis[e.u][h], h});
		}
	}
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> k >> n >> m;
	for (int i =0; i < m; i++) {
		int u, v, t, h;
		cin >> u >> v >> t >> h;
		adj[u].pb({v, t, h});
		adj[v].pb({u, t, h});
	}

	cin >> a >> b;
	
	dijkstra(a);
	for (int q = 0; q < k; q++)
		ans = min(ans, dis[b][q]);

	if (ans == 0x3f3f3f3f)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}
