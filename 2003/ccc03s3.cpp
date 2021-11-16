#pragma GCC target ("avx2")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
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

int area, r, c;
int recur(vt<vt<int>> &adj, int x, int y) {
	if (x <0 || x >= r || y < 0 || y >= c || adj[x][y]) return 0;
	adj[x][y] = 1;

	return 1+recur(adj, x-1, y)+recur(adj, x, y+1)+recur(adj, x+1, y)+recur(adj, x,y-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	read(area, r, c);
	vt<vt<int>> v(26, vt<int>(26));
	vt<int> rooms;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			char c; read(c);
			v[i][j] = c == 'I' ? 1 : 0;
		}
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (!v[i][j]) {
				int cur = recur(v, i, j);
				rooms.pb(cur);
			}
		}
	}
	//write(rooms);
	sort(all(rooms), greater<int>());
	if ((int)(rooms.size())==0) {
		print("0 rooms,", area, "square metre(s) left over");
		return 0;
	}
	int x = 0;
	int psa[(int)(rooms.size())];
	psa[0] = rooms[0];
	for (int i=1; i<(int)(rooms.size()); i++) {
		psa[i]= psa[i-1]+rooms[i];
	}
	//no room can be done
	if (psa[0] > area) {
	    print("0 rooms,", area, "square metre(s) left over");
	    return 0;
	}
	//all rooms can be done
	if (psa[(int)(rooms.size())-1] <= area) {
		if ((int)(rooms.size()) == 1) {
			print("1 room ", area-psa[(int)(rooms.size())-1], "square metre(s) left over\n");
			return 0;
		}
		else {
			print((int)(rooms.size()), "rooms,", area-psa[(int)(rooms.size())-1], "square metre(s) left over\n");
			return 0;
		}
	}
	for (int i=0; i<(int)(rooms.size()); i++) {
		if (psa[i] > area) {
			x = i;
			break;
		}
	}
	//for (auto x : psa) cout << x << " ";
	int cnt = area-psa[x-1];
	if (x==1) {
		write("1 room, ");
	}
	else {
		write(x, " rooms, ");
	}
	write(cnt, " square metre(s) left over", '\n');
	return 0;
}
