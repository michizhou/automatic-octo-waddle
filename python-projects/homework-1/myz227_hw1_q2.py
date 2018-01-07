def shift(lst, k, value='left'):
    totlength = len(lst)
    if value is 'right':
        for i in range(k):
            temp = lst[totlength-1]
            for j in range(totlength-1):
                lst[totlength-j-1] = lst[totlength-j-2]
            lst[0] = temp
    elif value is 'left':
        for i in range(k):
            temp = lst[0]
            for j in range(totlength-1):
                lst[j] = lst[j+1]
            lst[totlength-1] = temp
    print(lst)
