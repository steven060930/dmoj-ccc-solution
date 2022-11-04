#include "bits/stdc++.h"
using namespace std;

#define all(x) (x).begin(), (x).end()
#define ub upper_bound
#define lb lower_bound

template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if(!n) return cout; cout<<a[0]; for(int i=1;i<n;i++) cout<<' '<<a[i]; return cout; }

typedef long long ll; typedef long double ld;
typedef pair<double, double> pii; typedef pair<ll, ll> pll;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	int x; cin >> x;
	vector<pii> a;
	for (int i=0; i<x; ++i) {
		pii p; cin >> p;
		a.push_back(p);
	}

	sort(all(a));
	double ans=0;
	for (int i=1; i<x; ++i) {
		auto p1 = a[i], p2 = a[i-1];
		double speed = abs(p1.second - p2.second) / (p1.first - p2.first);
		ans = max(ans, speed);
	}

	cout << fixed << setprecision(7) << ans << '\n';
}
