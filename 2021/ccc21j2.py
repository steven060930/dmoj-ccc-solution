n = int(input())
l = []
for i in range(n):
    name = input()
    price = int(input())
    l.append((name, price))
l.sort(key = lambda x : x[1], reverse = True)
print(l[0][0])
