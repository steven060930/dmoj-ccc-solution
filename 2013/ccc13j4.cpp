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
        sum += v[i]; cnt++;
        if (sum > t)
            break;
    }
    printf("%d\n", cnt-1);
    return 0;
}
