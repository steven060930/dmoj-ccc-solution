#include "bits/stdc++.h"
using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define vt vector
typedef unsigned long long ull;	 typedef long long ll;	typedef long double ld;
const ll INF = 0x3f3f3f3f;	const ll LLINF = 0x3f3f3f3f3f3f3f3f;	const ll MOD = 1e9 +7;
template <typename C> void UNIQUE(vector<C> &v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}
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

ll dp[34];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(0);
	int a, b, n; read(a, b, n);
	vt<int> pos = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
	for (int i = 1; i <= n; i++) {
		int m; read(m);
		pos.pb(m);
	}
	
	sort(all(pos));
	dp[0] = 1;
	for (int i = 0; i < 14+n; i++) {
		for (int j = 0; j <= i; j++) {
			int dis = pos[i]-pos[j];
			if (dis >= a && dis <= b) dp[i] += dp[j];
		}
	}
	print(dp[13+n]);
	return 0;
}
