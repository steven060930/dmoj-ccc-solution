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

int N, M, d[101][101], vis[101][101];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void preprocess(vector<vector<char>> &adj) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (adj[i][j] == 'C') {
				bool flag1 = true;
				for (int k=i; k>=0 && flag1; k--) {
					if (adj[k][j] == 'W') flag1 = false;
					else if (adj[k][j] == '.' || adj[k][j] == 'S') vis[k][j] = 1;
				}
				bool flag2 = true;
				for (int k=i+1; k<N && flag2; k++) {
					if (adj[k][j] == 'W') flag2 = false;
					else if (adj[k][j] == '.' || adj[k][j] == 'S') vis[k][j] = 1;
				}
				bool flag3 = true;
				for (int k=j; k>=0 && flag3; k--) {
					if (adj[i][k] == 'W') flag3 = false;
					else if (adj[i][k] == '.' || adj[i][k] == 'S') vis[i][k] = 1;
				}
				bool flag4 = true;
				for (int k=j+1; k<M && flag4; k++) {
					if (adj[i][k] == 'W') flag4 = false;
					else if (adj[i][k] == '.' || adj[i][k] == 'S') vis[i][k] = 1;
				}
			}
		}
	}
}

void bfs(vector<vector<char>> &adj, pii src) {
	auto chk = [&](int x, int y) -> bool {
		return x >= 0 && x < N && y >= 0 && y < M;
	};

	auto better = [&](int dis, int r, int c) -> bool {
		return (chk(r, c) && adj[r][c] != 'W' && !vis[r][c] && dis < d[r][c]);
	};

	queue<pair<pii ,int>> q;
	if (!vis[src.first][src.second])
		q.push(make_pair(src, 0));
	d[src.first][src.second] = 0;
	while (q.size()) {
		auto cur = q.front(); q.pop();
		int dis = cur.second, row = cur.first.first, col = cur.first.second;
		if (dis > d[row][col]) continue;
		if (adj[row][col] == '.' || adj[row][col] == 'S') {
			for (int i=0; i<4; i++) {
				int r = row + dx[i], c = col + dy[i];
				if ((better(dis+1, r, c))) q.push({{r, c}, dis+1}), d[r][c] = dis+1;
			}
		}
		// conveyor, distance doesn't inc. by 1
		else if (adj[row][col] == 'L' && better(dis, row, col-1)) q.push({{row, col-1}, dis}), d[row][col-1] = dis;
		else if (adj[row][col] == 'R' && better(dis, row, col+1)) q.push({{row, col+1}, dis}), d[row][col+1] = dis;
		else if (adj[row][col] == 'U' && better(dis, row-1, col)) q.push({{row-1, col}, dis}), d[row-1][col] = dis;
		else if (adj[row][col] == 'D' && better(dis, row+1, col)) q.push({{row+1, col}, dis}), d[row+1][col] = dis;
	}
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> N >> M;
	vector<vector<char>> adj(N, vector<char>(M));
	pii src;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> adj[i][j];
			if (adj[i][j] == 'S') src = {i,j};
		}
	}
	
	preprocess(adj);
	memset(d, 0x3f3f3f3f, sizeof d);
	bfs(adj, src);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (adj[i][j] == '.') 
				cout << (d[i][j] == 0x3f3f3f3f? -1 : d[i][j]) << '\n';
		}
	}
}
