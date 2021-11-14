k = int(input())
s = str(input())
line = ""
for i in range(len(s)):
    t = ord(s[i])-((i+1)*3+k)
    if t < 65:
        t += 26
    line += chr(t)
print(line)
