s = input()
mx = 1
for i in range(len(s)+1):
    for j in range(i):
        if s[j:i] == s[j:i][::-1]:
            mx = max(mx, abs(j-i))
            
print(mx)
