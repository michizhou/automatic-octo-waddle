def split_by_sign(lst, low, high):
    if (low == high):
        return lst
    elif lst[low] > 0 and lst[high] < 0:
        lst[low], lst[high] = lst[high], lst[low]
        return split_by_sign(lst, low + 1, high - 1)
    else:
        if lst[low] < 0:
            return split_by_sign(lst, low + 1, high)
        elif lst[high] > 0:
            return split_by_sign(lst, low, high - 1)
    return lst

def permutations(lst, low, high):
    if lst:
        lst1, lst2 = [], []
        for index in range(low, high+1):
            if lst[index] not in lst2:
                tmp_lst = lst[low:high+1]
                tmp_lst.remove(lst[index])
                for item in permutations(tmp_lst, 0, len(tmp_lst)-1):
                    lst1.append([lst[index]]+item)
            lst2.append(lst[index])
        return lst1
    else:
        return [[]]

def find_duplicates(lst):
    freq_lst = [0]*len(lst)
    dup_lst = []
    for index in range(len(lst)):
        mod = lst[index] % len(lst)
        freq_lst[mod] += 1
    for i in range(len(lst)):
        if freq_lst[i] > 1:
            dup_lst.append(i)
    return dup_lst

def insert(self, index, val):
    if index < 0 or index >= len(self):
        raise IndexError("Index is out of bounds")
    else:
        if self.capacity < self.n + 1:
            self.resize(self.capacity * 2)
        self.n += 1
        for i in range(1, self.n - index):
            temp = self.data[self.n - i - 1]
            self.data[self.n - i - 1] = self.data[self.n - i - 2]
            self.data[self.n - i] = temp
        self.data[index] = val

def pop(self):
    if self.n == 0:
        raise IndexError("List object is empty")
    else:
        value = self.data[self.n - 1]
        self.data[self.n - 1] = None
        self.n -= 1
        if self.n < self.capacity / 4:
            self.capacity //= 2
        return value

def pop(self, index): #Extra Credit Implementation
    if self.n == 0:
        raise IndexError("List object is empty")
    else:
        value = self.data[index]
        for i in range(index, self.n-1):
            self.data[i] = self.data[i+1]
        self.data[self.n-1] = None
        self.n -= 1
        if self.n < self.capacity / 4:
            self.capacity //= 2
        return value

def remove_all(lst, value):
    for index in range(len(lst)):
        if lst[index] == value:
            lst[index] = None
    lst[:] = [num for num in lst if num != None]