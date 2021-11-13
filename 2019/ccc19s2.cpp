#include <bits/stdc++.h>
/*
#include <boost/range/algorithm/count.hpp>
#include <bits/c++config.h>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/detail/container_base_dispatch.hpp>
#include <ext/pb_ds/detail/branch_policy/traits.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
*/
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

typedef unsigned long long ull;
typedef unsigned char char64;
typedef long long ll;
typedef long double ld;
typedef short int si;
typedef unsigned short int usi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

const ll INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INPOSSIBLE = -1;
const ll big = 1e9 +5;
const ll prime = 1e9 +7;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mpair make_pair
#define mtuple make_tuple
#define pb push_back

template <typename T> int SZ(T &v) { return v.size(); }
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

bool check(ll n) {
	if (n == 2) {return true;}
	for (int i=2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			return false;
			break;
		}
	}
	return true;
}

void solve() {
	ll n;
	read(n);
	for (ll i=2; i < 2*n; ++i) {
		if (check(i) && check(2*n-i)) {
			cout << i << " " << 2*n-i << "\n";
			return ;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	read(t);
	while (t--) {
		solve();
	}
	return 0;
}
