#include <bits/stdc++.h>
/*
#include <boost/range/algorithm/count.hpp>
#include <bits/c++config.h>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/detail/container_base_dispatch.hpp>
#include <ext/pb_ds/detail/branch_policy/traits.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
*/
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")

//#define max(a, b) (a > b) ? a : b
//#define maximum(x, y, z) max(max(x, y), z)
#define SQUARE(n) ((n)*(n))
#define CUBE(n) ((n)*(n)*(n))
#define SQRT(n) (pow(n, 0.5))
#define SIGN(n) (((n) < 0) ? -1 : 1)
#define ABS(n) (((n) < 0) ? -(n) : (n))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define gcd(a, b) (b == 0) ? a : gcd(b, a%b)
#define rup(a) ((a+0.5) >= (int(a)+1)) ? (int(a)+1) : int(a)
#define rdown(b) (int(b))
#define fnd(x, y) (x).find(y) != (x).end()
#define FORI(a, b, u) for(int i = a; i < b; i+=u)
#define FORJ(m, n, o) for(int j = m; j < n; j+=o)

#define scan(x) { while((x=getchar())<'0'); for (x-='0'; '0'<= (_=getchar()); x = (x<<3)+(x<<1)+_-'0');} while(0)
char _;

typedef unsigned long long ull;
typedef unsigned char char64;
typedef long long ll;
typedef long double ld;
typedef short int si;
typedef unsigned short int usi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

const ll INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INPOSSIBLE = -1;
const ll big = 1e9 +5;
const ll prime = 1e9 +7;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mpair make_pair
#define mtuple make_tuple
#define pb push_back

template <typename T> int SZ(T &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(all(v)); v.resize(unique(all(v)) - v.begin()); } 
template <typename U> void DECREASING(vector<U> &v) { sort(all(v), greater<U>()); }

template<class T> void read(T& x) {
	cin >> x;
} 
void read(double &d) {
	string t;
	read(t);
	d = stod(t);
}
void read(ld &d) {
	string t;
	read(t);
	d = stold(t);
}
template<class H, class... T> void read(H& h, T&...t) {
	read(h);
	read(t...);
}
template<class A> void read( vector<A> &x) {
	for (auto &a : x) {
		read(a);
	}
}

vector<vector<int>> adj(10001);

int n;

struct Point{
	int x;
	int dist;
};

int bfs(vector<vector<int>> &v) {
	bool vis[n];
	memset(vis, false, sizeof(vis));
	Point start = {1, 1};
	queue<Point> q;
	q.push(start);
	vis[start.x-1] = true;
	while (q.size()) {
		Point cur = q.front();
		q.pop();
		int x = cur.x;
		int d = cur.dist;
	//	cout << x << " " << d << endl;
		if (v[x-1].size() == 0) {
			return d;
			break;
		}

		for (auto i : v[x-1]) {
			if (!vis[i-1]) {
				vis[i-1] = true;
				q.push({i, d+1});
			}
		}
	}
	return 1;
}

bool bfs2(vector<vector<int>> &v) {
	bool vis[n];
	memset(vis, false, sizeof(vis));
	queue<int> q;
	q.push(1);
	vis[0] = true;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		for (auto x: v[cur-1]) {
			if (!vis[x-1]) {
				vis[x-1] = true;
				q.push(x);
			}
		}
	}
	for (auto a : vis) {
		if (a == false) {
			return false;
			break;
		}
	}
	return true;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	read(n);
	vector<vector<int>> m;
	for (int i=0; i< n; i++) {
		int temp;
		read(temp);
		if (temp == 0) {
			m.pb({});
			continue;
		}
		else {
			vector<int> v(temp);
			read(v);
			m.pb(v);
		}
	}
	for (int i=0; i< n; ++i) {
		for (auto y : m[i]) {
			adj[i].pb(y);
		}
	}
	string ans = bfs2(adj)? "Y" : "N";
	cout << ans << endl;
	int a = bfs(adj);
	cout << a << endl;
	return 0;
}
