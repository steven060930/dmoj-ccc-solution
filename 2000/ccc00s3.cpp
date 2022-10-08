// ccc00s3 - surfing
#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define _rep(i, v) for (int i = 0; i < (int)(v); i ++)
#define _rep1(i, v) for (int i = 1; i <= (int)(v); i++)
#define F_OR (x, v) for (auto &x: v) 

using namespace std;
typedef long long ll; typedef long double ld;
typedef pair<int, int> pii;

int N; vector<string> urls, storage;
map<string, vector<string>> g;
const string _DIR = "A HREF=";

string print(string s, int pos) {
	string res = "";
	for (int i=pos+8; i<s.size()-1; i++) {
		res += s[i];
		if (s[i+1] == '"') break;
	}
	return res;
}

bool search(string src, string dest) {
	queue<string> q; q.push(src);
	map<string, int> vis;
	for (auto c: urls)
		vis.insert(make_pair(c, 0));

	while (q.size()) {
		string cur = q.front(); q.pop();
		if (cur == dest)
			return true;

		for (auto &e: g[cur]) {
			if (!vis[e]) {
				vis[e] = 1;
				q.push(e);
			}
		}
	}
	return false;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		string URL; cin >> URL;
		urls.push_back(URL);
		string emp; getline(cin, emp);
		while (true) {
			string c; getline(cin, c);
			if (c == "</HTML>") break;
			auto found = 0;
			while (c.find(_DIR, found) != string::npos || found > c.size()) {
				cout << "Link from " << URL << " to ";
				string dest = print(c, c.find(_DIR, found));
				cout << print(c, c.find(_DIR, found)) << '\n';
				if (g.find(URL) == g.end()) 
				{ vector<string> tmp={}; tmp.push_back(dest), g.insert(make_pair(URL, tmp)); }
				else
					g[URL].push_back(dest);

				found = c.find(_DIR, found) + 1;
			}
		}
	}

	while (true) {
		string line; getline(cin, line);
		if (line == "The End") break;

		storage.push_back(line);
	}

	for (int i=0; i+1<storage.size(); i+=2) {
		string d1= storage[i], d2= storage[i+1];
		if (search(d1, d2)) 
			cout << "Can surf from " << d1 << " to " << d2 << '.' << '\n';
		else 
			cout << "Can't surf from " << d1 << " to " << d2 << '.' << '\n';
	}
}


