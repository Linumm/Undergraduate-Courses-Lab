#7-2 2.py

answer=input().split()
a=int(answer[0])
b=float(answer[1])

a2=2*a
a4=4*a
a8=8*a

b2=2*b
b4=4*b
b8=8*b

c1='%.2f'%b2
c2='%.2f'%b4
c3='%.2f'%b8

print('%10d'%a2,'%10d'%a4, '%10d'%a8)
print('%10s'%c1, '%10s'%c2, '%10s'%c3)

