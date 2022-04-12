#include "bits/stdc++.h"
using namespace std;

int cnt;
int x, y, g;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> x;
	vector<pair<string, string> > cmd1, cmd2;
	map<string, int> mpp;
	for (int i = 0; i < x; i++) {
		string s, t; cin >> s >> t;
		cmd1.push_back(make_pair(s, t));
	}
  
	cin >> y;
	for (int i = 0; i < y; i++) {
		string s, t; cin >> s >> t;
		cmd2.push_back(make_pair(s, t));
	}
  
	cin >> g;
	for (int i = 0; i < g; i++) {
		string r, s, t; cin >> r >> s >> t;
		mpp.insert(make_pair(r, i));
		mpp.insert(make_pair(s, i));
		mpp.insert(make_pair(t, i));
	}

	for (auto p : cmd1) {
		string u = p.first, v = p.second;
		if (mpp[u] != mpp[v]) cnt++;
	}
	for (auto p : cmd2) {
		string u = p.first, v = p.second;
		if (mpp[u] == mpp[v]) cnt++;
	}

	cout << cnt << '\n';
}
