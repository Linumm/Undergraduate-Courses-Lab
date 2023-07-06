#7-2 4.py

while True:
    answer=ord(input())
    if 65<=answer<=90:
        print(chr(answer+32))
    elif 97<=answer<=122:
        print(chr(answer-32))
    elif 48<=answer<=57:
        print(chr(answer))
    else:
        break
