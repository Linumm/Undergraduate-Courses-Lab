#4-2 1.py
def printLine(n):
    for i in range(1, n+1):
        print(i , end=' ')
    print()

a=int(input())

for m in range(1, a+1):
    printLine(m)
    
for m in range(a, 0, -1):
    printLine(m)



    
