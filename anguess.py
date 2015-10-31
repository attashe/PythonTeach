
a = 0
b = 99
i = 0
while True:
    i += 1
    t = (a + ((b-a)//2))
    print (t)
    x = input('input ')
    if x == '>':
        a = t
    elif x == '<':
        b = t
    else:
        break

print (i)



