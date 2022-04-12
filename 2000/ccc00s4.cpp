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

int dp[5301];
const int INF = 1061109567;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(0);
	//dp keep track of each distance, dp[i] means at dis = i
	int dis, n; fin(dis, n); vt<int> v(n); fin(v);
	memset(dp, INF, sizeof(dp)); dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < dis+1; ++j) {
			if (v[i] <= j) dp[j] = min(dp[j], dp[j-v[i]] + 1);
		}
	}

	if (dp[dis] == INF) print("Roberta acknowledges defeat.");
	else print("Roberta wins in", dp[dis], "strokes.");

	return 0;
}
