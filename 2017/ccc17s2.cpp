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

int main() {
	cin.tie(nullptr) -> sync_with_stdio(0);
	int n; read(n);
	vt<int> v(n); read(v);
	int mid = (n%2) ? (n+1)/2 : n/2;
	vt<int> low, high;
	sort(all(v));
	for (int i = 0 ; i < mid; i++)
		low.pb(v[i]);
	for (int i = mid; i < n; i++)
		high.pb(v[i]);
	sort(all(low), greater<int>()); sort(all(high));
	for (int i = 0; i < (int)(n/2); i++) {
		write(low[i], ' ', high[i], ' ');
	}
	if (n % 2) {
		print(low[mid-1]);
	} else { cout << "\n"; }
	return 0;
}
