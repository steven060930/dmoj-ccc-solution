#include <bits/stdc++.h>
using namespace std;

int data[22][2] = {
	2, 6,
	6, 1,
	6, 3,
	6, 4,
	6, 5,
	6, 7,
	3, 4,
	3, 15,
	3, 5,
	4, 5,
	15, 13,
	13, 14,
	13, 12,
	12, 9,
	12, 11,
	11, 10,
	10, 9,
	8, 9,
	7, 8,
	16, 18,
	18, 17,
	17, 16
};

void add(int adj[50][50], int x, int y) {
	adj[x][y] = adj[y][x] = 1;
}

void del(int adj[50][50], int x, int y) {
	adj[x][y] = adj[y][x] = 0;
}

int bfs(int adj[50][50], int x, int y) {
	queue<int> q;
	int vis[50];
	memset(vis, 0, sizeof (vis));
	for (int i=0; i< 50; i++) {
		if (adj[x][i]) {
			vis[i] = 1;
			q.push(i);
		}
	}

	while (q.size()){
		int s = q.front();
		q.pop();

		if (s == y) {
			return vis[s];
		}

		for (int i=0; i< 50; i++) {
			if (adj[s][i] && vis[i]==0) {
				vis[i] = vis[s] + 1;
				q.push(i);
			}
		}
	}
	return -1;
}

int counter(int adj[50][50], int start) {
    int count[51];
    memset(count, 0, sizeof count);
    count[start] = 1;
	int total = 0;
    for (int i=0; i< 50; i++) {
		if (adj[start][i]) {
			count[i] = 1;
		}
	}

	for (int i=0; i< 50; i++) {
		if (adj[start][i]) {
			for (int j=0; j< 50; j++) {
				if (adj[i][j] && count[j] == 0) {
					total += 1;
					count[j] = 1;
				}
			}
		}
	}
	return total;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int x, y;
	int adj[50][50];
	memset(adj, 0, sizeof adj);
	for (int i=0; i< 22; ++i) {
		adj[data[i][0]][data[i][1]] = adj[data[i][1]][data[i][0]] = 1;
	}	
	for (;;) {
        char temp;
        // all of the possible choices input
        cin >> temp;
        if (temp == 'q') {
			return 0;            
		}
        if (temp == 'i') {
            cin >> x >> y;
            add(adj, x, y);
        }
        if (temp == 'd') {
            cin >> x >> y;
            del(adj, x, y);
        }
        if (temp == 'n') {
            cin >> x;
			int cnt = 0;
			for (auto &a : adj[x]) {
				if (a) cnt++;
			}
			cout << cnt << "\n";
		}
        if (temp == 'f') {
            cin >> x;
            cout << counter(adj, x) << "\n";
        }
        if (temp == 's') {
            cin >> x >> y;
            int d = bfs(adj, x, y);
            if (d != -1) { cout << d << endl; }
            else { cout << "Not connected\n"; }
        }
    }
    return 0;
}
