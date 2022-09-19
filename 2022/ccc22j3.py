alpha, number = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789"
s = input()
line = ""
ok = 0
for i in range(len(s)):
    if i == len(s)-1:
        line += s[i]
        print(line) #[println the solution]
        break #break out the whole for loop
    if s[i] in alpha:
        line += s[i]
    elif s[i] == "+":
        line += " tighten "
    elif s[i] == "-":
        line += " loosen "
    
    if s[i] in number:
        if s[i+1] not in number:
            line += s[i]
            line += "\n"
        else: line += s[i]
