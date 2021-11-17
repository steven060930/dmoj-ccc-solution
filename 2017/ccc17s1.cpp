#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int n, arr1[(int)(1e7+1)], arr2[(int)(1e7+1)];
ll ans1=0, ans2=0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for (int i=1; i<=n; i++) cin >> arr1[i];
	for (int i=1; i<=n; i++) cin >> arr2[i];
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		ans1 += arr1[i]; ans2 += arr2[i];
		if (ans1 == ans2) cnt=i;
	}
	cout << cnt << '\n';
	return 0;
}
