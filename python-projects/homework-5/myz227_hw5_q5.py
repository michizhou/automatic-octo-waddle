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

def permutations(lst):
    if lst is None:
        return []
    lst = sorted(lst)
    permutation = []
    stack = ArrayStack()
    stack.push(-1)
    all_permutations = Queue()
    total_lst = []
    while len(stack):
        index = stack.pop()
        index += 1
        while index < len(lst):
            if lst[index] not in permutation:
                break
            index += 1
        else:
            if len(permutation):
                permutation.pop()
            continue

        stack.push(index)
        stack.push(-1)
        permutation.append(lst[index])
        if len(permutation) == len(lst):
            all_permutations.enqueue(list(permutation))
        while len(all_permutations) > 0:
            total_lst.append(all_permutations.dequeue())
    return total_lst