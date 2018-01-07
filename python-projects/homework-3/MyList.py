import ctypes  # provides low-level arrays
def make_array(n):
    return (n * ctypes.py_object)()

class MyList:
    def __init__(self):
        self.data = make_array(1)
        self.capacity = 1
        self.n = 0


    def __len__(self):
        return self.n


    def append(self, val):
        if (self.n == self.capacity):
            self.resize(2 * self.capacity)
        self.data[self.n] = val
        self.n += 1


    def resize(self, new_size):
        new_array = make_array(new_size)
        for i in range(self.n):
            new_array[i] = self.data[i]
        self.data = new_array
        self.capacity = new_size


    def extend(self, other):
        for elem in other:
            self.append(elem)


    def __getitem__(self, ind):
        if (not (-len(self) <= ind <= self.n - 1)):
            raise IndexError('Index is out of range')

        return self.data[ind]


    def __setitem__(self, ind, val):
        if (not (-len(self) <= ind <= self.n - 1)):
            raise IndexError('Index is out of range')

        self.data[ind] = val

    def insert(self, index, val):
        if index < 0 or index > len(self):
            raise IndexError("Index is out of bounds")
        else:
            if self.capacity < self.n + 1:
                self.resize(self.capacity * 2)
            self.n += 1
            for i in range(1,self.n-index):
                temp = self.data[self.n-i-1]
                self.data[self.n-i-1] = self.data[self.n-i-2]
                self.data[self.n-i] = temp
            self.data[index] = val

    def pop(self):
        if self.n == 0:
            raise IndexError("List object is empty")
        else:
            value = self.data[self.n - 1]
            self.data[self.n - 1] = None
            self.n -= 1
            if self.n < self.capacity // 4:
                self.capacity //= 2
            return value

    def __str__(self):
        new_str = "["
        for index in range(self.n):
            new_str += str(self[index])
            if index != len(self)-1:
                new_str += ", "
        new_str += "]"
        return new_str

    def __repr__(self):
        return str(self)

    def __add__(self, other):
        if len(self) != len(other):
            raise ValueError("Dimensions must agree")
        result = MyList()
        result.resize(len(self))
        for i in range(len(self)):
            result[i] = self[i] + other[i]
        return result

    def __iadd__(self, other):
        if self.capacity < len(self) + len(other):
            self.resize(self.capacity * 2)
        self.extend(other)
        return self

    def __mul__(self, n):
        result = MyList()
        result.resize(len(self))
        for factor in range(n):
            for j in range(len(self)):
                result[len(self)*factor + j] = self[j]
        return result

    def __rmul__(self, n):
        result = MyList()
        result.resize(len(self))
        for factor in range(n):
            for j in range(len(self)):
                result[len(self) * factor + j] = self[j]
        return result


def reverse_string(input_str, low, high):
    if low == high:
        return input_str[low]
    else:
        rest = reverse_string(input_str, low+1, high)
        new_str = rest + input_str[low]
        return new_str







