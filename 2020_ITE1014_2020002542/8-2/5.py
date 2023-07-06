#8-2 5.py

def comb(n, r):
    if r==0 or r==n:
        return 1
    else:
        return comb(n-1, r)+comb(n-1, r-1)

nr=input().split()
n=int(nr[0])
r=int(nr[1])

print(comb(n, r))
