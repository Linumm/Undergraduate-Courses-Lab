#4-2 2.py
def problemDescription():
    print('* Number of divisors *')

def getNumOfDivisors(number):
    dn=0
    for i in range(1,number+1):
        if number%i==0:
            dn=dn+1
    return(dn)

problemDescription()
print('Type the first number:')
num1=int(input())
print('Type the second number:')
num2=int(input())

num1=str(getNumOfDivisors(num1))
num2=str(getNumOfDivisors(num2))

print('Number of divisors of the first number is '+num1)
print('Number of divisors of the second number is '+num2)
