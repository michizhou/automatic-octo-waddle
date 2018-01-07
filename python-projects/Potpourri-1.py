def maximum(lst):
    if len(lst) == 1:
        return lst[0]
    else:
        value = maximum(lst[1:])
        return max(lst[0], value)

def rsum(L):
    if type(L) != list:
        return L
    if L == []:
        return 0
    return rsum(L[0]) + rsum(L[1:])

import random

def roll_the_dice_str(n):
    chars = []
    for i in range(1, n+1):
        curr_val = random.randint(1, 6)
        chars.append(str(curr_val))
    return ' '.join(chars)

def find_intersection(lst1, lst2):
    i, j = 0, 0
    intersect_lst = []
    while i < len(lst1) and j < len(lst2):
        if lst1[i] < lst2[j]:
            i += 1
        elif lst1[i] > lst2[j]:
            j += 1
        else:
            intersect_lst.append(lst2[j])
            i += 1
            j += 1
    return intersect_lst

def advancing(a):
    '''a is an array of integer, which is the number
    of step one can move forward from that position.
    check if we can reach the end of a
    '''
    furthest = 0
    for i in range(len(a)):
        furthest = max(furthest, a[i] + i)
        if furthest == i:
            return False
    if furthest >= len(a) - 1:
        return True
    else:
        return False