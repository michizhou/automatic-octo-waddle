class Empty(Exception):
    pass

class ArrayStack:
    def __init__(self):
        self.data = []

    def __len__(self):
        return len(self.data)

    def is_empty(self):
        return len(self) == 0

    def push(self, val):
        self.data.append(val)

    def top(self):
        if (self.is_empty()):
            raise Empty("Stack is empty")
        return self.data[-1]

    def pop(self):
        if (self.is_empty()):
            raise Empty("Stack is empty")
        return self.data.pop()

class ArrayDeque:
    INITIAL_CAPACITY = 10
    
    def __init__(self):
        self.first = 0
        self.data = [None] * ArrayDeque.INITIAL_CAPACITY
        self.n = 0

    def __len__(self):
        return self.n

    def __str__(self):
        return str(self.data)

    def is_empty(self):
        return self.n == 0

    def first(self):
        return self.data[self.first]

    def last(self):
        last = (self.first + self.n - 1) % len(self.data)
        return self.data[last]

    def add_first(self, e):
        if(self.n==len(self.data)):
            self.resize(2*self.n)
        new_first = (self.first - 1)%len(self.data)
        self.data[new_first] = e
        self.first = new_first
        self.n += 1

    def add_last(self, e):
        if(self.n == len(self.data)):
            self.resize(2*self.n)
        new_last = (self.first + self.n)%(len(self.data))
        self.data[new_last] = e
        self.n += 1

    def delete_first(self):
        if not self.is_empty():
            first_elem = self.data[self.first]
            self.data[self.first] = None
            self.first = (self.first + 1)%(len(self.data))
            self.n -= 1

            if(self.n < len(self.data)//4):
                self.resize(len(self.data)//2)
            return first_elem
        else:
            raise Empty("Deque is currently empty")

    def delete_last(self):
        if not self.is_empty():
            last = (self.first + self.n - 1)% len(self.data)
            last_elem = self.data[last]
            self.data[last] = None
            self.n -= 1
            if(self.n < len(self.data)//4):
                self.resize(len(self.data)//2)
            return last_elem
        else:
            raise Empty("Deque is currently empty")

    def resize(self, newcap):
        old = self.data
        self.data = [None]*newcap
        curr = self.first

        for k in range(self.n):
            self.data[k] = old[curr]
            curr += 1
            curr %= len(old)

        self.first = 0

class MidStack:
    def __init__(self):
        self.stack = ArrayStack()
        self.deque = ArrayDeque()

    def __len__(self):
        return len(self.deque) + len(self.stack)

    def is_empty(self):
        return len(self) == 0

    def push(self, e):
        if self.is_empty():
            self.stack.push(e)
        elif len(self) % 2 == 0:
            self.stack.push(self.deque.delete_first())
            self.deque.add_last(e)
        else:
            self.deque.add_last(e)

    def top(self):
        if self.is_empty():
            raise Empty("Deque has no elements")
        return self.deque.last()

    def pop(self):
        if (self.is_empty()):
            raise Empty("Deque has no elements")
        if len(self) % 2 != 0:
            self.deque.add_first(self.stack.pop())
        return self.deque.delete_last()

    def mid_push(self, e):
        if len(self) % 2 == 1:
            self.deque.add_first(e)
        elif len(self) % 2 == 0:
            self.stack.push(e)