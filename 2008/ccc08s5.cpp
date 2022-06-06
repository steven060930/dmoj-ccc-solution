#include "bits/stdc++.h"
using namespace std;

#define vt vector
#define mpr make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) (int)(x.size())

typedef long long ll;	typedef long double ld;

int n;
int a, b, c, d;
int mv[5][4] = {
	{2, 1, 0, 2},
	{1, 1, 1, 1},
	{0, 0, 2, 1},
	{0, 3, 0, 0},
	{1, 0, 0, 1}
};
bool dp[33][33][33][33];

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> n;
	for (int a=0; a<31; a++) {
		for (int b=0; b<31; b++) {
			for (int c=0; c<31; c++) {
				for (int d=0; d<31; d++) {
					for (int i=0; i<5; i++) {
						if (a >= mv[i][0] && b >= mv[i][1] && c >= mv[i][2] && d >= mv[i][3])
							if (!dp[a-mv[i][0]][b-mv[i][1]][c-mv[i][2]][d-mv[i][3]])
								dp[a][b][c][d] = 1;
					}
				}
			}
		}
	}

	for (int i=1; i<=n; i++) {
		cin >> a >> b >> c >> d;
		cout << (dp[a][b][c][d] ? "Patrick" : "Roland") << '\n';
	}
}
