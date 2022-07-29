cnt = 0
for i in range(6):
    s = input()
    if s == 'W':
        cnt += 1
if cnt == 5 or cnt == 6:
    print(1)
elif cnt == 3 or cnt == 4:
    print(2)
elif cnt == 1 or cnt == 2:
    print(3)
else:
    print(-1)
