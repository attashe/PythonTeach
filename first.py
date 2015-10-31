def frame_lines(string):
    a = 0
    xs = []
    for i in range(len(string)):
        if string[i] == '\n':
            xs += [string[a:i]]
            a = i + 1
        elif i == (len(string) - 1):
            xs += [string[a:i+1]]
    max = 0
    for str in xs:
        if len(str)>max:
            max = len(str)
    print ((u'\u2502') + ('-'*(max+2)) + (u'\u2502'))
    for str in xs:
        print ((u'\u2502')+ ' ' + str + (' ' * (max - len(str))) +' ' + (u'\u2502'))
    print ((u'\u2502') + ('-'*(max+2)) + (u'\u2502'))






frame_lines ('First string\nSecond string\nThird string')

