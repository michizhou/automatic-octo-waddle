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

class MaxStack:
    def __init__(self):
        self.stack = ArrayStack()
        self.maxValue = 0

    def __len__(self):
        return len(self.stack)

    def is_empty(self):
        return len(self) == 0

    def push(self, e):
        if self.is_empty() or e > self.maxValue:
            self.maxValue = e
        self.stack.push((e, self.maxValue))

    def top(self):
        if self.is_empty():
            raise Empty("MaxStack is empty")
        element = self.stack.top()
        return element[0]

    def pop(self):
        if (self.is_empty()):
            raise Empty("MaxStack is empty")
        element = self.stack.pop()
        return element[0]

    def max(self):
        value = self.stack.top()
        return value[-1]