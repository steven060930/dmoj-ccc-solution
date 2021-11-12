def check(s):
    if len(s) == 0:
        return False
    if s == "A":
        return True

    if s[0] == 'B' and s[len(s)-1] == 'S':
        if check(s[1:-1]):
            return True

    for i in range(len(s)):
        if s[i] == 'N':
            if i == 0:
                continue
            if check(s[:i]) and check(s[i+1: ]):
                return True
    return False


while True:
    st = str(input())
    if st == "X":
        break
    else:
        print("YES") if check(st) else print("NO")
