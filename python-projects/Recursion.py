def is_palindrome(input_str, low, high):
    if low <= high:
        if input_str[low] != input_str[high]:
            return False
        else:
            is_palindrome(input_str, low+1, high-1)
    return True

def binary_search(srt_lst, val, low, high):
    mid = int((low + high) / 2)
    if low <= high:
        if srt_lst[mid] == val:
            print(mid)
        elif srt_lst[mid] > val:
            binary_search(srt_lst, val, low, mid-1)
        else:
            binary_search(srt_lst, val, mid+1, high)
    return None

def decimal_to_binary(input_int):   #print direct to screen
    if input_int > 1:
        decimal_to_binary(input_int//2)
    print(input_int % 2, end='')

def decToBin(n):        #return string representation
    if n==1:
        return '1'
    else:
        return decToBin(n//2) + str(n%2)

def solve_hanoi(n, frm, to, extra):
    if n == 1:
        print("move disk from", frm, "to", to)
        return
    else:
        solve_hanoi(n-1,frm,extra,to)
        print("move disk from", frm, "to", to)
        solve_hanoi(n-1,extra,to,frm)

import os

def disk_usage(path):
    """Return the number of bytes used by a file/folder and any descendants."""
    total = os.path.getsize(path) # account for direct usage
    if os.path.isdir(path): # if this is a directory,
        for filename in os.listdir(path): # then for each child:
            childpath = os.path.join(path, filename) # compose full path to child
            total += disk_usage(childpath) # add child’s usage to total

    print ('{0:<7}'.format(total), path) # descriptive output (optional)
    return total