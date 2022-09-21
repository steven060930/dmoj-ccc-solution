n, count = int(input()), 0

for i in range(6):
    for j in range(6):
        if i + j == n:
            if i == j:
                count += 2
            else:
                count += 1
                
print(count//2)
