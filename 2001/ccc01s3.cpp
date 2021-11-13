#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")

#define gcd(a, b) (b == 0) ? a : gcd(b, a%b)
#define rup(a) ((a+0.5) >= (int(a)+1)) ? (int(a)+1) : int(a)
#define rdown(b) (int(b))
#define fnd(x, y) (x).find(y) != (x).end()

#define scan(x) { while((x=getchar())<'0'); for (x-='0'; '0'<= (_=getchar()); x = (x<<3)+(x<<1)+_-'0');} while(0)
char _;

#define vt vector
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

const ll INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 +7;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mpair make_pair
#define pb push_back
#define nl cout << "\n"

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
template<class A> void read( vector<A> &x) {
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

template<size_t S> string to_string(bitset<S> b) {
	string res;
	for (int i=0; i < S; i++) 
		res+=char('0'+b[i]);
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

void remove(vt<int> &v, int target) {
	for (auto i = v.begin(); i!= v.end(); i++) {
		if (*i == target) {
			v.erase(i);
			return ;
		}
	}
}

bool bfs(vt<vt<int>> v, int x, int y) {
	// x is the starting point, y is the ending point
	remove(v[x], y);	remove(v[y], x);
	queue<int> q;
	bool vis[27];
	q.push(x);
	memset(vis, false, sizeof(vis));
	while (q.size()) {
		int cur = q.front();
		q.pop();
		if (cur == y) {
			return true;
			break;
		}
		for (auto i : v[cur]) {
			if (!vis[i]) {
				vis[i] = true;
			    q.push(i);	
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vt<vt<int>> grid(27);	vt<pair<int, int>> v;
	for (;;) {
		string temp;
		read(temp);
		if (temp == "**") {
			break;
		}
		else {
			int x, y;
			x = temp[0]-64;
			y = temp[1]-64;
			//write(x, ' ', y);
			grid[x].pb(y); grid[y].pb(x);	v.pb(mpair(x, y));
		}
	}
	
	int cnt = 0;
	for (auto x : v) {
		int f = x.fi, y = x.se;
		if (!bfs(grid, f, y)) {
			write(char(f+64), char(y+64), "\n");
			cnt++;
		}
	}
	cout << "There are " << cnt << " disconnecting roads." << endl;
	return 0;
}
