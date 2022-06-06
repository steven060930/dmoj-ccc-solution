cnt =0
n = int(input())
for _ in range(n):
    x = int(input())
    y = int(input())
    if 5*x - 3*y >= 40: cnt += 1
print(cnt) if cnt != n else print(cnt, '+', sep="")
