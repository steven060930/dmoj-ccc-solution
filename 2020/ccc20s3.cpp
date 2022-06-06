#include "bits/stdc++.h"
using namespace std;

#define ar array
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

ar<int, 26> fqh;
ar<int, 26> fqn;
ll p = 31, m = (ll)(1e13+5);

ll hashing(string const& s) {
	ll pwr = 31, res = 0;
	for (int i=0; i < sz(s); i++) {
		res = (res * p + s[i]) % m;
		pwr = (pwr * p) % m;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string haystack, needle;
	read(needle, haystack);
	ll s = 1;
	for (int i = 0; i < sz(needle); i++) {
		fqh[(int)haystack[i] - 'a']++;
		fqn[(int)needle[i] - 'a']++;
		s = (s * p) % m;
	}
	//print(hashing("abb"));

	set<ll> hashes;
	ll hash_val = hashing(haystack.substr(0, sz(needle))), cnt = 0;

	for (int i = 0; i < sz(haystack)-sz(needle)+1; i++) {
		if (fqh == fqn) {
			if (hashes.find(hash_val) == hashes.end()) {
				hashes.insert(hash_val);
				cnt++;
			}
		}
		hash_val = ((hash_val * p) + haystack[i+sz(needle)]) % m;
		hash_val -= (s * haystack[i]) % m;

		if (hash_val < 0) 
		    hash_val += m;

		fqh[(int)haystack[i] - 'a']--;
		fqh[(int)haystack[i+sz(needle)] - 'a']++;
	}

	print(sz(hashes));
}
