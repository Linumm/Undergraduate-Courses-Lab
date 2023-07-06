#5-1 1.py
a=input().split()
b=input().split()
c=input().split()
d=input().split()
e=input().split()



dic={a[0]:a[1], b[0]:b[1], c[0]:c[1], d[0]:d[1], e[0]:e[1]}

print("Which student's score?")
name=input()
if name in dic:
    print(name+" 's score: "+dic[name])
else:
    print(name+' is not in the database.')
    
