n, m, k = map(int, input().split())
if k < n or k > (n-m)*m+(1+m)*m/2: print(-1)
else:
    a = [0] * n
    cur = a[0] = 1
    k -= 1
    for i in range(1, n):
        if k-cur > n-i-1 and a[i-1] + 1 <= m:
            a[i] = a[i-1]+1
            if cur < m: cur += 1
            k -= cur
        else:
            while k-cur < n-i-1: cur -= 1
            a[i] = a[i-cur]
            k -= cur
    print(*a)
    
# only passed in pypy3
