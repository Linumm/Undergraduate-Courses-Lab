#6-2 4.py
integers=input().split()
integers[0]=int(integers[0])
integers[1]=int(integers[1])
integers[2]=int(integers[2])

maxNum=integers[0]
minNum=integers[0]

if integers[0]<integers[2]:
    maxNum=integers[2]
    if integers[2]<integers[1]:
        maxNum=integers[1]
    elif integers[1]<integers[0]:
        minNum=integers[1]
    
elif integers[0]<integers[1]:
    maxNum=integers[1]
    if integers[1]<integers[2]:
        maxNum=integers[2]
    elif integers[2]<integers[0]:
        minNum=integers[2]

elif integers[0]>integers[1]:
    minNum=integers[1]
    if integers[1]>integers[2]:
        minNum=integers[2]
        
print("min: "+str(minNum))
print("max: "+str(maxNum))
