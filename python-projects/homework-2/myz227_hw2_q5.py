def split_parity(lst):
    left = 0
    right = len(lst)-1
    while left < right:
        while lst[left] % 2 == 1:
            left += 1
        while lst[right] % 2 == 0:
            right -= 1
        temp = lst[left]
        lst[left] = lst[right]
        lst[right] = temp
    print(lst)