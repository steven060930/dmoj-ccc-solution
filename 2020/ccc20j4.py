s = input()
t = input()
l = []
for i in range(len(t)):
    b = t[1:len(t)] + t[0]
    t = b
    l.append(b)
for a in l:
    if s.find(a) != -1:
        print("yes")
        break
else:
    print("no")
