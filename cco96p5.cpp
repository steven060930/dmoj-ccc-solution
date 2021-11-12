#pragma GCC target ("avx2")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define gcd(a, b) (b == 0) ? a : gcd(b, a%b)
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mpair make_pair
#define pb push_back
#define nl cout << "\n"

#define scan(x) { while((x=getchar())<'0'); for (x-='0'; '0'<= (_=getchar()); x = (x<<3)+(x<<1)+_-'0');} while(0)
char _;

#define vt vector
typedef unsigned long long ull;	 typedef long long ll;	typedef long double ld;

const ll INF = 0x3f3f3f3f;	const ll LLINF = 0x3f3f3f3f3f3f3f3f;	const ll MOD = 1e9 +7;

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
template<class A> void read(vector<A> &x) {
	for (auto &a : x) {
		read(a);
	}
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	for (int i=0; i < (int)v.size(); i++)
		res+=char('0'+v[i]);
	return res;
}

template<class T> string to_string(T v) {
    bool f=1;
    string res;
    for (auto &x :v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
template<class C> void write(vt<C> &v) {
	for (auto &x : v) { cout << x << " "; }
	nl;
}
template<class A> void write(vt<vt<A>> &v) {
	for (auto x : v) { for (auto y : x) { cout << y << " "; } nl;}
}

bool dfs(vt<vt<int>> &adj, int m, int n, vt<int> &path, vt<int> &vis) {
	vis[m] = 1;
	path.pb(m);
	if (m == n) {return true;}

	for (auto i : adj[m]) {
		if (!vis[i]) {
			if (dfs(adj, i, n, path, vis)) {
				return true;
			}
		}
	}
	path.pop_back();

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n;
	read(m, n);
	vt<vt<int>> adj(27);
	for (int i=0; i<m; i++) {
		string s, t;
		read(s, t);
		int x= s[0]-'A'+1, y = t[0]-'A'+1;
		adj[x].pb(y); adj[y].pb(x);
	}
	for (int i=0; i<n; i++) {
		string start, end;
		read(start, end);
		vt<int> path;	vt<int> vis(27);
		string res = "";
		int st = start[0]-'A'+1, en = end[0]-'A'+1;
		if (dfs(adj, st, en, path, vis)) {
			for (auto x : path) {
				res += (char)(x + 'A'-1);
			}
		}
		write(res, '\n');
	}
	return 0;
}
