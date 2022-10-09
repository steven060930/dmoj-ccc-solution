#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define _rep(i, v) for (int i = 0; i < (int)(v); i ++)
#define _rep1(i, v) for (int i = 1; i <= (int)(v); i++)
#define F_OR (x, v) for (auto &x: v) 

using namespace std;
typedef long long ll; typedef long double ld;
typedef pair<int, int> pii;

int vis[201][401];

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	memset(vis, 0 , sizeof vis);
	vis[0][200] = 1;
	vis[1][200] = 1;
	vis[2][200] = 1;
	vis[2][201] = 1;
	vis[2][202] = 1;
	vis[2][203] = 1;
	vis[3][203] = 1;
	vis[4][203] = 1;
	vis[4][204] = 1;
	vis[4][205] = 1;
	vis[3][205] = 1;
	vis[2][205] = 1;
	vis[2][206] = 1;
	vis[2][207] = 1;
	vis[3][207] = 1;
	vis[4][207] = 1;
	vis[5][207] = 1;
	vis[6][207] = 1;
	vis[6][206] = 1;
	vis[6][205] = 1;
	vis[6][204] = 1;
	vis[6][203] = 1;
	vis[6][202] = 1;
	vis[6][201] = 1;
	vis[6][200] = 1;
	vis[6][199] = 1;
	vis[5][199] = 1;
	vis[4][199] = 1;

	pii cur = { 4, 199 };
	while (true) {
		char c; int a;
		cin >> c >> a;
		if (c == 'q') return 0;
		if (c == 'l') {
			bool chk = 0;
			for (int i=0; i<a; i++) {
				cur.second -= 1;
				if (vis[cur.first][cur.second] == 0) 
					vis[cur.first][cur.second] = 1;
				else
				{	chk = 1; continue; }
			}

			if (chk)
			{	cout << cur.second-200 << ' ' << (-1)*cur.first-1 << " DANGER\n"; return 0;  }
			else
				cout << cur.second-200 << ' ' << (-1)*cur.first-1 << " safe\n";
		}

		else if (c == 'r') {
			bool chk = 0;
			for (int i=0; i<a; i++) {
				cur.second += 1;
				if (vis[cur.first][cur.second] == 0) 
					vis[cur.first][cur.second] = 1;
				else
				{  chk = 1; continue; }
			}

			if (chk) 
			{	cout << cur.second-200 << ' ' << (-1)*cur.first-1 << " DANGER\n"; return 0;  }
			else
				cout << cur.second-200 << ' ' << (-1)*cur.first-1 << ' ' << "safe\n";
		}

		else if (c == 'u') {
			bool chk = 0;
			for (int i=0; i<a; i++) {
				cur.first -= 1;
				if (vis[cur.first][cur.second] == 0) 
					vis[cur.first][cur.second] = 1;
				else
				{ chk =1; continue; }
			}

			if (chk)
			{	cout << cur.second-200 << ' ' << (-1)*cur.first-1 << " DANGER\n"; return 0;  }
			else
				cout << cur.second-200 << ' ' << (-1)*cur.first-1 << " safe\n";
		}

		else if (c == 'd') {
			bool chk = 0;
			for (int i=0; i<a; i++) {
				cur.first += 1;
				if (vis[cur.first][cur.second] == 0)
					vis[cur.first][cur.second] = 1;
				else
				{	chk = 1; continue; }
			}

			if (chk)
			{	cout << cur.second-200 << ' ' << (-1)*cur.first-1 << " DANGER\n"; return 0;  }
			else
				cout << cur.second-200 << ' ' << (-1)*cur.first-1 << " safe\n";
		}
	}
}
