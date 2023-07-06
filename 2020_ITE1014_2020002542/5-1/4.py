#5-1 4.py
import random
stlist=[]
def getRandomString(leng):
    for i in range(0, leng):
        n=random.randint(97,122)
        stlist.insert(i, chr(n))
        string=''.join(stlist)
    return string

length=int(input())
print(getRandomString(length))
