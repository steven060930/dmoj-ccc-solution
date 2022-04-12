#include "bits/stdc++.h"
using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define vt vector
typedef unsigned long long ull;	 typedef long long ll;	typedef long double ld;
template <typename C> void UNIQUE(vector<C> &v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}
template <typename T> int sz(T &v) { return (int)(v.size()); }

template<class T> void fin(T& x) { cin >> x; } 
void fin(double &d) {
	string t; fin(t);
	d = stod(t);
}
void fin(ld &d) {
	string t; fin(t);
	d = stold(t);
}
template<class H, class... T> void fin(H& h, T&...t) {
	fin(h); fin(t...);
}
template<class A> void fin(vector<A> &x) {
	for (auto &a : x) { fin(a); }
}

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b?"true":"false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vt<bool> v) {
	string res;
	for (int i=0; i < (int)v.size(); i++)
		res+=char('0'+v[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1; string res;
    for (auto &x :v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
    }
    return res;
}

template<class A> void write(A x) { cout << to_string(x); }
template<class H, class... T> void write(const H& h, const T&... t) { write(h); write(t...); }

void print() { write("\n"); }
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

int n, t, k, d;
vt<vt<pair<int, int>>> adj(5005);

void dijkstra(vt<int> &price, int src) {
	ll dis[5005]; memset(dis, 0x3f3f3f3f, sizeof dis);
	priority_queue<int, vt<int>, greater<int> > q; q.push(src); dis[src]=0;
	while (sz(q)) {
		int cur = q.top(); q.pop();
		
		for (pair<int, int> &p : adj[cur]) {
			if (dis[cur] != 0x3f3f3f3f && dis[cur]+p.se < dis[p.fi]) {
				dis[p.fi] = dis[cur]+p.se;
				q.push(p.fi);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		dis[i+1] += price[i];
	}

	ll ans = 1e16;
	for (int i = 1; i <= n; i++) {
		if (i == src || price[i-1]==0) continue;
		ans = min(ans, dis[i]-1);
	}
	print(ans);
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(0);
	fin(n, t);
	for (int i = 0; i < t; i++) {
		int x, y, c; fin(x, y, c);
		adj[x].pb(mpr(y, c)); adj[y].pb(mpr(x, c));
	}
	fin(k);
	vt<int> price(n);
	for (int i = 0; i < k; i++) {
		int x, y; fin(x, y); price[x-1] = y+1;
	}
	fin(d); //denoted the destination node,
	// we reverse the problem start dijkstra at source
	dijkstra(price, d);
	return 0;
}
