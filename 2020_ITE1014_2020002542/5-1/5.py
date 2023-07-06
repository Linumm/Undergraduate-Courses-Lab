#5-1 5.py
import random
cheeseList=[]
cheese=''
ratThinkList=[]
def getRandomCheese(size):
    global cheese
    for i in range(0, size):
        n=random.randint(97,122)
        cheeseList.insert(i, chr(n))
        cheese=''.join(cheeseList)
    return cheese

def cheeseCheck(cheese, ratThink):
    
    for i in range(0, len(cheese)):
        if ratThink==cheese[i]:
            cheese=cheese[:i]+'_'+cheese[i+1:]
    return cheese


cheesesize=random.randint(10,30)
getRandomCheese(cheesesize)
originCheese=cheese
print('Cheese is '+cheese)

alphabet='a b c d e f g h i j k l m n o p q r s t u v w x y z'.split()
x=0

for i in range(10):
    while True:
        n=random.randint(0,25-x)
        m=alphabet[n]
        if m in alphabet:
            del alphabet[n]
            x=x+1
            break
    ratThink=m
    cheese=cheeseCheck(cheese, ratThink)
    print('I thought '+ratThink)
    print('Original cheese is '+originCheese+' ,Now Cheese is '+cheeseCheck(cheese, ratThink))
    if cheese==('_'*cheesesize):
        print('Out of cheese!')
        break
    
if cheese!= ('_'*cheesesize):
    print('Rat Has Failed: '+cheeseCheck(cheese, ratThink))
    
    
    
    
    



        
    
