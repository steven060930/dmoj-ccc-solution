l_, _l = [], []
for _ in range(int(input())):
    temp = input()
    idx = 0
    for i in range(len(temp)):
        if temp[i] == ',': idx = i
    x, y = int(temp[0:idx]), int(temp[idx+1: ])
    l_.append(x)
    _l.append(y)
l_.sort()
_l.sort()
print(f'{l_[0]-1},{_l[0]-1}')
print(f'{l_[len(l_)-1]+1},{_l[len(_l)-1]+1}')
