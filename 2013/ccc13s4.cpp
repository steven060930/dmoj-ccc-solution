#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
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

vector<vector<int>> adj(1000000);
int m, n;

bool bfs(int a, int b) {
    bool vis[n];
    memset(vis, false, sizeof(vis));
    queue<int> q;
    vis[a] = true;
    q.push(a);
    
    while (q.size()) {
        int curr = q.front();
        q.pop();
        if (curr == b) {
            return true;
            break;
        }
        
        for (auto x : adj[curr]) {
            if (!vis[x]) {
                vis[x] = true;
                q.push(x);
            }
        }
    }
    return false;
}


bool reverse_bfs(int a, int b) {
    bool vis[n];
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(b);
    vis[b] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == a) {
            return true;
            break;
        }
        for (int x: adj[curr]) {
            if (!vis[x]) {
                vis[x] = true;
                q.push(x);
            }
        }
    }
    return false;
}

int main() {
  ios::sync_with_stdio(0);
	cin.tie(nullptr);
	read(n, m);
	for (int i=0; i< m; i++) {
	    int x, y;
	    read(x, y);
	    adj[x].pb(y);
	}
	int p, q;
	read(p, q);
	if (!bfs(p,q) && !reverse_bfs(p,q)) {
	    cout << "unknown" << "\n";
	}
	else if (!bfs(p, q) && reverse_bfs(p, q)) {
	    cout << "no" << "\n";
	}
	else {
	    cout << "yes" << "\n";
	}
	return 0;
}
