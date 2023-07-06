#8-1 4.py

def sigma(n):
    if n<=1:
        return 1
    else:
        return (n+sigma(n-1))

n=int(input())
print(sigma(n))
