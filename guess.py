from random import randint

x = randint (0,99)
i = 0
while True:
    n = int(input('input '))
    i += 1
    if n < x:
        print ('more')
    elif n > x:
        print ('less')
    else:
        print ('well done')
        break
print (i)
