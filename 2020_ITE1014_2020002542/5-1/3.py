#5-1 3.py
syntax=input()
syntax=syntax.split()

dic={}
for i in range(0, len(syntax)):
    if syntax[i] not in dic:
        dic[syntax[i]]=1
    elif syntax[i] in dic:
        dic[syntax[i]]=dic[syntax[i]]+1

for i in dic:
    print(i+ ': '+str(dic[i]))
    
    
    
    
    
    

