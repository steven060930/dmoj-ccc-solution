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

int d1[2] = {0, 0}, d2[2] = {1, -1};
int d3[2] = {1, -1}, d4[2] = {0, 0};
int all_d1[4] = {1, 0, 0, -1};
int all_d2[4] = {0, 1, -1, 0};

struct Point {
	int x;
	int y;
	int dist;
};

bool Valid(Point x, int r, int c) {
	return (x.x >= 0 && x.x < r) && (x.y >=0 && x.y < c);
}

int bfs(vt<vt<char>> &v, Point start, Point end, int r, int c) {
	if (v[r-1][c-1] == '*') {return -1;}
	bool vis[21][21];
	memset(vis, false, sizeof(vis));
	queue<Point> q;
	q.push(start);
	for (int i=0; i < r; i++) {
		for (int j=0; j< c; j++) {
			if (v[i][j] == '*') {
				vis[i][j] = true;
			}
		}
	}
	while (q.size()) {
		Point curr = q.front();
		q.pop();
		if (curr.x == end.x && curr.y == end.y) {
			return curr.dist+1;
			break;
		}
		if (!vis[curr.x][curr.y]) {
			vis[curr.x][curr.y] = true;
			if (v[curr.x][curr.y]  == '-') {
				for (int i=0; i< 2; i++) {
					int x1 = curr.x + d1[i], y1 = curr.y + d2[i];
					if (Valid({x1, y1, 0}, r, c)) {
						q.push({x1, y1, curr.dist+1});
					}
				}
			}
			else if (v[curr.x][curr.y] == '|') {
				for (int i=0; i<2; i++) {
					int x1 = curr.x + d3[i], y1 = curr.y+d4[i];
					if (Valid({x1, y1, 0}, r, c)) {
						q.push({x1, y1, curr.dist+1});
					}
				}
			}
			else if (v[curr.x][curr.y] == '+') {
				for (int i=0; i< 4; i++) {
					int x1 = curr.x + all_d1[i], y1 = curr.y + all_d2[i];
					if (Valid({x1, y1, 0}, r, c)) {
						q.push({x1, y1, curr.dist+1});
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	read(t);
	while (t--) {
		int r, c;
		read(r, c);
		vt<vt<char>> grid(r, vt<char>(c));
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				read(grid[i][j]);
			}
		}
		int ans = bfs(grid, {0, 0, 0}, {r-1, c-1, 0}, r, c);
		cout << ans << "\n";
	}
	return 0;
}
