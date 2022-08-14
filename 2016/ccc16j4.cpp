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

int H, M, HH, MM; int current, remain;

int main() {
    scanf("%02d:%02d", &H, &M);
	
	remain = 240;
	current = H*60 + M;

	while (1) {
		if ((420 <= current && current <= 600) || (900 <= current && current <= 1140)) remain--;
		else 	remain -= 2;

		if (remain < 0) break;

		current = (current + 1) % 1440;
	}

	HH = current / 60;
	MM = current % 60;

	printf("%02d:%02d", HH, MM);
}
