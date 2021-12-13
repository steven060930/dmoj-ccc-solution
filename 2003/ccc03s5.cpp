#include "bits/stdc++.h"
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define vt vector
typedef unsigned long long ull;	 typedef long long ll;	typedef long double ld;
template <typename T> int sz(T &v) { return (int)(v.size()); }

template<class T> void read(T& x) { cin >> x; } 
void read(double &d) {
	string t; read(t);
	d = stod(t);
}
void read(ld &d) {
	string t; read(t);
	d = stold(t);
}
template<class H, class... T> void read(H& h, T&...t) {
	read(h); read(t...);
}
template<class A> void read(vector<A> &x) {
	for (auto &a : x) { read(a); }
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

struct edge {
	int u;
	int v;
	int w;
};

int n, m, d, ans, p[100005];
vt<int> dest; vt<edge> ve;

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}
int main() {
	cin.tie(nullptr) -> sync_with_stdio(0);
	read(n, m, d);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int x, y, z; read(x, y, z);
		ve.pb({x, y, z});
	}
	for (int i = 1, x; i <= d; i++) {
		read(x); dest.pb(x);
	}
	sort(all(ve), [](edge &a, edge &b) {return a.w > b.w;});
	for (int i = 0, j = 0; j < sz(dest); j++) {
		int x = dest[j];
		for (; find(1) != find(x); i++) {
			int u = find(ve[i].u), v = find(ve[i].v);
			if (u != v) {
				p[u] = v; ans = ve[i].w;
			}
		}
	}
	print(ans);
	return 0;
}
