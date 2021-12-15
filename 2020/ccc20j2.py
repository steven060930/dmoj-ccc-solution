p = int(input())
n = int(input())
r = int(input())
i, ans = 0, 0
while True:
    ans += pow(r, i)*n
    i += 1
    if ans > p:
        print(i-1)
        break
