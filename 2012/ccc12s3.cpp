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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; read(n);
	vt<int> v(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		read(v[i]);
		if (mp.find(v[i]) == mp.end()) {
			mp.insert(mpr(v[i], 1));
		}
		else {
			mp[v[i]]++;
		}
	}
	int c1=-1, c2=-1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		c1 = max(it->se, c1);
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->se >= c2 && it->se != c1) {
			c2 = it->se;
		}
	}
	//print(c1, c2);
	if (c2 == -1) {
		sort(all(v));
		print(abs(v[0]-v[n-1]));
		return 0;
	}
	else {
		vt<int> v1, v2;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			if (it->se == c1) v1.pb(it->fi);
			if (it->se == c2) v2.pb(it->fi);
		}
		if (sz(v1) >= 2) {
			int m = -1;
			sort(all(v1));
			for (int i = 1; i < sz(v1); i++) {
				m = max(m, v1[i]-v1[i-1]);
			}
			print(m);
		}
		else {
			int mx = -1;
			for (int i = 0; i < sz(v1); i++) {
				for (int j = 0; j < sz(v2); j++) {
					mx = max(mx, abs(v1[i]-v2[j]));
				}
			}
			print(mx);
		}
	}
	return 0;
}
