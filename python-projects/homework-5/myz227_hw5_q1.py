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

class Queue:
    def __init__(self):
        self.enstack = ArrayStack()
        self.destack = ArrayStack()
        self.num_elems = 0

    def __len__(self):
        return self.num_elems

    def is_empty(self):
        return len(self) == 0

    def enqueue(self, item):
        self.enstack.push(item)
        self.num_elems += 1

    def dequeue(self):
        if not self.destack:
            while self.enstack:
                self.destack.push(self.enstack.pop())
        self.num_elems -= 1
        return self.destack.pop()

    def first(self):
        if not self.destack:
            while self.enstack:
                self.destack.push(self.enstack.pop())
        return self.destack.top()