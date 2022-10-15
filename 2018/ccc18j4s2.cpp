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
typedef pair<int, int> pii; typedef pair<ll, ll> pll;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int N;

bool chk(vector<vector<int>> &adj) {
	auto s = [&] (vector<int> &a) -> bool {
		vector<int> b = a;
		sort(all(b));
		return a == b;
	};

	bool ok = 1;
	for (auto row: adj) {
		if (!s(row)) {
			ok = 0; break;
		}
	}

	for (int i=1; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (adj[i][j] <= adj[i-1][j] && ok) {
				ok = false; break;
			}
		}
	}

	return ok;
}

vector<vector<int>> rotate(vector<vector<int>> &adj) {
	vector<vector<int>> res(N, vector<int> (N));
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			res[i][j] = adj[N-j-1][i];
		}
	}
	return res;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> N;
	vector<vector<int>> data(N, vector<int> (N));
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> data[i][j];
		}
	}


	while (true) {
		if (!chk(data)) {
			data = rotate(data);
		}
		else {
			for (int i=0; i<N; i++) {
				for (int j=0; j<N; j++) {
					cout << data[i][j] << ' ';
				}
				cout << '\n';
			}
			return 0;
		}
	}
}


/*
 * 4 3 1
 * 6 5 2
 * 9 7 3
 *
 * counter-clockwise
 *
 * 1 2 3
 * 3 5 7
 * 4 6 9
 *
 * [0, 2] -> [0, 0]
 * [1, 2] -> [0, 1]
 * [2, 0] -> [2, 2]
 */
