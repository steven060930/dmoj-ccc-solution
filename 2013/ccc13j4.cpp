#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t, n, cnt = 0, sum = 0;
    scanf("%d %d", &t, &n);
    int v[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v, v+n);
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (sum > t) break;
        else cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
