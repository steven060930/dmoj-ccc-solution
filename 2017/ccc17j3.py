a, b = map(int, input().split())
c, d = map(int, input().split())
t = int(input())

print("Y") if (t-abs(a-c) - abs(b-d)) % 2 == 0 and (t-abs(a-c) - abs(b-d))>=0 else print("N")
