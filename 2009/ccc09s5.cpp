#include "bits/stdc++.h"
using namespace std;

#define mpr make_pair
#define sz(x) (int)(x.size())
#define pow2(x) (x)*(x)

typedef long long ll;	typedef long double ld;

const int mxN = 1003;
const int mxM = 3e4+5;

int N, M, K, ans, cnt;
int x[mxN], y[mxN], r[mxN], b[mxN];
int d[mxN][mxM];

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	cin >> M >> N >> K;
	for (int i=0; i<K; i++) {
		cin >> x[i] >> y[i] >> r[i] >> b[i];
		for (int j=max(1, x[i]-r[i]); j<=min(N, x[i]+r[i]); j++) {
			int su = sqrt(pow2(r[i])-pow2(x[i]-j));
			d[j][max(1, y[i]-su)]+=b[i]; d[j][min(M, y[i]+su)+1]-=b[i];
		}
	}

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=M; j++) {
			d[i][j] += d[i][j-1];
			if (d[i][j] > ans) 
				ans=d[i][j], cnt=1;
			else if (d[i][j]==ans)
				cnt++;
		}
	}

	cout << ans << '\n';
	cout << cnt << '\n';
}
