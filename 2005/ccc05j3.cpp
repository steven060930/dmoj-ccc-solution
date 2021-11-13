#pragma GCC target ("avx2")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define nl cout << "\n"
#define vt vector
typedef unsigned long long ull;	 typedef long long ll;	typedef long double ld;

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
template<class C> void write(vt<C> &v) {
	for (auto &x : v) { cout << x << " "; }
	nl;
}
template<class A> void write(vt<vt<A>> &v) {
	for (auto x : v) { for (auto y : x) { cout << y << " "; } nl; }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vt<string> dirc, spot;
	while (1) {
		string s, t;
		read(s, t);
		dirc.pb(s); spot.pb(t);
		if (t == "SCHOOL") {
			break;
		}
	}
	reverse(all(dirc));
	for (auto &x : dirc) {
		if (x=="R") x="LEFT";
		else if (x == "L") x="RIGHT";
	}
	//write(dirc);
	reverse(all(spot));
	for (int i=1; i<(int)(spot.size()); i++) {
		write("Turn ", dirc[i-1], " onto ", spot[i], " street.", "\n");
	}
	write("Turn ", dirc[(int)(spot.size())-1], " into your HOME.", "\n");
	return 0;
}
