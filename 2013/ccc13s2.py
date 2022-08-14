#this solution only pass in python3, NOT pypy
maxWeight = int(input())
N = int(input())

trains, onBridge, crossed = [int(input()) for i in range(N)], [], 0

for train in trains:
    onBridge.append(train)
    if len(onBridge) > 4:
        onBridge.pop(0)
    if sum(onBridge) <= maxWeight:
        crossed += 1
    else:
        break

print(crossed)
