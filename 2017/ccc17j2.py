n = int(input())
k = int(input())
cnt = n
for i in range(k):
    cnt += n*10
    n*=10
print(cnt)