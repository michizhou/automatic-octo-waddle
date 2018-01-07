def print_triangle(n):
    if n == 1:
        print("*")
    else:
        print_triangle(n-1)
        for index in range(n):
            print("*", end='')
        print('')

def print_oposite_triangles(n):
    if n == 1:
        print("*")
    else:
        for index in range(n):
            print("*", end='')
        print('')
        print_oposite_triangles(n-1)
    for index in range(n):
        print("*", end='')
    print('')

def print_ruler(n):
    if (n > 0):
        print_ruler(n-1)
    for num in range(n):
        print("-", end='')
    print('')
    if (n > 0):
        print_ruler(n-1)

def list_min(lst, low, high):
    size = high - low + 1
    if size == 1:
        return lst[high]
    else:
        return min(lst[high], list_min(lst, low, high - 1))

def count_lowercase(s, low, high):
    size = high - low + 1
    if size == 1:
        count = 0
        if ord(s[0]) - ord('a') >= 0:
            count += 1
        return count
    else:
        total = 0
        if ord(s[high]) - ord('a') >= 0:
            total += 1
        total += count_lowercase(s, low, high - 1)
        return total

def is_number_of_lowercase_even(s, low, high):
    if low - high == 0:
        if ord(s[low]) - ord('a') >= 0:
            return False
        else:
            return True
    else:
        if ord(s[low]) - ord('a') >= 0:
            if is_number_of_lowercase_even(s, low+1, high):
                return False
            else:
                return True
        else:
            if is_number_of_lowercase_even(s, low+1, high):
                return True
            else:
                return False

def appearances(s, low, high):
    str_dict = {}
    if high - low == 0:
        str_dict.update({s[high]: 1})
        return str_dict
    else:
        str_dict.update(appearances(s, low, high-1))
        if s[high] in str_dict.keys():
            str_dict.update({s[high]: str_dict.get(s[high])+1})
        else:
            str_dict.update({s[high]: 1})
        return str_dict

def flat_list(nested_lst, low, high):
    new_lst = []
    for element in nested_lst[low:high+1]:
        if type(element) == type([]):
            new_lst.extend(flat_list(element, 0, len(element) - 1))
        else:
            new_lst.append(element)
    return new_lst