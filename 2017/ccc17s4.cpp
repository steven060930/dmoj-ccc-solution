#include "bits/stdc++.h"
using namespace std;

#define vt vector
#define mpr make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) (int)(s.size())

typedef long long ll;	typedef long double ld;

struct edge {
	int src, dest, w, stat;
};
bool cmp(edge A, edge B) {
	if (A.w == B.w) return A.stat < B.stat;
	return A.w < B.w;
}

// N bulidings, M pipes connected (directly)
// pipe only spend C[i] per month when activated
const int MX = 1e5+3, MN = 2e5+5;
int n, m, d, p[MN], r[MN], cnt=0; vt<edge> pipes;

int fnd(int d) {
	if (d != p[d]) p[d] = fnd(p[d]);
	return p[d];
}

void un(int a, int b) {
	int pa = fnd(a), pb = fnd(b);
	if (pa == pb) return ;
	else if (r[pa] < r[pb]) p[pa] = pb;
	else if (r[pa] > r[pb]) p[pb] = pa;
	else {
		p[pb] = pa;
		++r[pa];
	}
}

bool ok(int x, int y) {
	int px = fnd(x), py = fnd(y);

	if (px == py) return 0;

	if (r[px] < r[py]) p[px] = py;
	else if (r[py] < r[px]) p[py] = px;
	else {
		p[py] = px; ++r[px];
	}
	return 1;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> n >> m >> d;

	for (int i = 0; i <= MN; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		if (i < n-1) pipes.pb({x, y, z, 0});
		else pipes.pb({x, y, z, 1});
	}
	
	sort(all(pipes), cmp);

	int mx=0, cur = 0, start=0;

	for (int i = 0; i < m; i++) {
		if (n - 1 == cur) { start = i; break; }
		if (ok(pipes[i].src, pipes[i].dest)) {
			cur++;
			mx = pipes[i].w;
			cnt += pipes[i].stat;
		}
	}

	if (pipes[start-1].stat) { // status: on
		for (int i = 0; i <= MN; i++) p[i] = i;
		for (auto E: pipes) {
			if (fnd(E.src) != fnd(E.dest)) { // not cycle;
				if (E.w < mx || (E.w == mx && !E.stat)) un(E.src, E.dest);
				else if (E.stat == 0 && E.w <= d) {
					cout << cnt-1 << '\n';
					return 0;
				}
			}
		}
	}
	//Kruskal's algorithm, dsu to find cycle find(src) != find(dest)
	//
	cout << cnt << '\n';
}
