#4-1 3.py
gMul=1
def addTotal(n):
    return(n*(n+1)/2)

def mulTotal(n):
    global gMul
    for i in range(1, n+1):
        gMul=gMul*i

n=int(input())
mulTotal(n)
print('addTotal(): '+str(addTotal(n)))
print('gMul: '+str(gMul))
gMul=1
