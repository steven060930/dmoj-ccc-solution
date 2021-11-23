#include "bits/stdc++.h"
using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define scan(x) { while((x=getchar())<'0'); for (x-='0'; '0'<= (_=getchar()); x = (x<<3)+(x<<1)+_-'0');} while(0)
char _;
#define vt vector
typedef unsigned long long ull;	 typedef long long ll;	typedef long double ld;
const ll INF = 0x3f3f3f3f;	const ll LLINF = 0x3f3f3f3f3f3f3f3f;	const ll MOD = 1e9 +7;
template <typename C> void UNIQUE(vector<C> &v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}
template <typename T> int sz(T &v) { return (int)(v.size()); }

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
	for (auto &a : x) { read(a); }
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
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

vt<vt<int>> adj(8);
vt<int> tmp(8, 0);

void topo_sort() {
	int cnt = 0;
	priority_queue<int, vt<int>, greater<int>> q;
	vt<int> order;
	for (int i = 0; i < sz(tmp); i++) {
		if (tmp[i] == 0) {
			q.push(i);
		}
	}
	while (sz(q)) {
		int cur = q.top();
		q.pop();
		order.pb(cur); cnt++;
		for (auto x : adj[cur]) {
			--tmp[x];
			if (tmp[x] == 0) {
				q.push(x);
			}
		}
	}
	if (cnt < 7) {
		print("Cannot complete these tasks. Going to bed.");
		return ;
	}
	for (int i = 1; i < sz(order); i++) {
		cout << order[i] << " ";
	}
	print();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	adj[1].pb(4);
	adj[1].pb(7);
	adj[2].pb(1);
	adj[3].pb(4);
	adj[3].pb(5);
	tmp[4] = 2;
	tmp[7] = tmp[1] = tmp[5] = 1;
	for (;;) {
		pair<int, int> p;
		read(p.fi, p.se);
		if (p.se == 0 && p.fi == 0) break;
		adj[p.fi].pb(p.se);
		tmp[p.se]++;
	}
	topo_sort();
	return 0;
}
