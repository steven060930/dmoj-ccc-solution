chk=1
grid = []
for i in range(4):
    ar = list(map(int, input().split()))
    grid.append(ar)
    
#check all rows
for i in range(1, 4):
    if sum(grid[i]) == sum(grid[i-1]):
        continue
    else:
        chk = 0
    
#check all columns
s = grid[0][0] + grid[1][0] + grid[2][0] + grid[3][0]
for i in range(1, 4):
    if grid[0][i] + grid[1][i] + grid[2][i] + grid[3][i] != s and chk:
        chk = 0
        break
    else:
        continue
    
print("magic") if chk else print("not magic")
