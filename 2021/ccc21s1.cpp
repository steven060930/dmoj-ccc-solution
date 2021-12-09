#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<double> v(1+n), vi(n);
	for (int i = 0;i<n+1; i++) {cin >> v[i];}
	for (int j=0; j < n; j++) {cin >> vi[j];}
	long double ans = 0;
	for (int i=0; i < n; i++) ans += vi[i]*0.5*(v[i]+v[i+1]);
	cout << fixed << setprecision(2) << ans << "\n";
}
