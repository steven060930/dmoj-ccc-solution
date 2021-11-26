a, b, c = int(input()), int(input()), int(input())
if a + c + b != 180:
    print("Error")
else:
    if a == b == c == 60:
        print("Equilateral")
    else:
        if a == 60:
            if b == c:
                print("Equilateral")
            else:
                print("Scalene")
        if b == 60:
            if a == c:
                print("Equilateral")
            else:
                print("Scalene")
        if c == 60:
            if b == a:
                print("Equilateral")
            else:
                print("Scalene")
        elif b == c or a == b or a == c:
            print("Isosceles")
