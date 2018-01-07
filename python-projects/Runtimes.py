def move_zeroes(nums):
    count = 0
    for index in range(len(nums)):
        if nums[index] != 0:
            nums[count] = nums[index]
            count += 1
    while count < len(nums):
        nums[count] = 0
        count += 1

def reverse_vowels(input_str):
    vowels = "aeiou"
    chr_array = list(input_str)
    low, high = 0, len(input_str) - 1
    while low < high:
        if chr_array[low] not in vowels:
            low += 1
        elif chr_array[high] not in vowels:
            high -= 1
        else:
            chr_array[low], chr_array[high] = chr_array[high], chr_array[low]
            low += 1
            high -= 1
    return ''.join(chr_array)

#Square root of n implementation
def square_root(num):
    i = 0
    while i*i < num:
        i += 1
        if i*i == num:
            return float(i)
    i -= 1
    dec = 0.5
    while dec < 1 and dec > 0:
        m = i + dec
        pow = m * m
        if abs(pow - num) < 0.01:
            return m
        elif pow < num:
            dec -= 0.01
        else:
            dec += 0.01

#Log n implementation
def sqrt(n):
    start = 0
    end = n
    m = 0
    min_range = 0.0000000001

    while end - start > min_range:
        m = (start + end) / 2.0
        pow2 = m * m
        if abs(pow2 - n) <= min_range:
            return m
        elif pow2 < n:
            start = m
        else:
            end = m
    return m