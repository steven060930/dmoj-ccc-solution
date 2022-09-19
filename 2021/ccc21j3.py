prev = ""
while True:
    code = input()
    if code == "99999":
        break

    s = int(code[0]) + int(code[1])

    if s == 0:
        pass
    elif s % 2 == 0:
        prev = "right"
    else:
        prev = "left"
    print(prev, code[2:])
