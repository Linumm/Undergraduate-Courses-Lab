#8-2 3.py

def fibona(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        return fibona(n-1)+fibona(n-2)

n=int(input())
print(fibona(n))
