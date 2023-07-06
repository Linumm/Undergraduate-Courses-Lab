#5-1 2.py
import random
list=[]

for i in range(0,100):
    list.insert(i, random.randint(1,1000))

for i in range(0,100):
    print(list[i],end=' ')
print()
print()

maxValue=0
for i in range(0,100):
    if list[i]>maxValue:
        maxValue=list[i]

print('max value: '+str(maxValue))
