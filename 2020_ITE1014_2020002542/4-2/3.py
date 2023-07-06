#4-2 3.py
def printStarDia(n):
    for i in range(1, n+1):
        a=i
        while a!=n:
            print('',end=' ')
            a=a+1
        for m in range(1, i+1):
            print('*',end=' ')
        print()

    for i in range(n, 0, -1):
        a=i
        while a!=n:
            print('',end=' ')
            a=a+1
        for m in range(1, i+1):
            print('*',end=' ')
        print()


n=int(input())
printStarDia(n)
        
            
    
