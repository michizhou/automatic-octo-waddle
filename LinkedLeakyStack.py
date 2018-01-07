class Empty(Exception):
    pass

class DoublyLinkedList:
    class Node:
        def __init__(self, data=None, next=None, prev=None):
            self.data = data
            self.next = next
            self.prev = prev

        def disconnect(self):
            self.data = None
            self.next = None
            self.prev = None

    def __init__(self):
        self.header = DoublyLinkedList.Node()
        self.trailer = DoublyLinkedList.Node()
        self.header.next = self.trailer
        self.trailer.prev = self.header
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return (len(self) == 0)

    def first_node(self):
        if (self.is_empty()):
            raise Empty("List is empty")
        return self.header.next

    def last_node(self):
        if (self.is_empty()):
            raise Empty("List is empty")
        return self.trailer.prev

    def add_first(self, elem):
        return self.add_after(self.header, elem)

    def add_last(self, elem):
        return self.add_after(self.trailer.prev, elem)

    def add_after(self, node, elem):
        prev = node
        succ = node.next
        new_node = DoublyLinkedList.Node()
        new_node.data = elem
        new_node.prev = prev
        new_node.next = succ
        prev.next = new_node
        succ.prev = new_node
        self.size += 1
        return new_node

    def add_before(self, node, elem):
        return self.add_after(node.prev, elem)

    def delete(self, node):
        prev = node.prev
        succ = node.next
        prev.next = succ
        succ.prev = prev
        self.size -= 1
        data = node.data
        node.disconnect()
        return data

    def __iter__(self):
        if(self.is_empty()):
            return
        cursor = self.first_node()
        while(cursor is not self.trailer):
            yield cursor.data
            cursor = cursor.next

    def __str__(self):
        return '[' + '<-->'.join([str(elem) for elem in self]) + ']'

    def __repr__(self):
        return str(self)

class LinkedStack:
    def __init__(self):
        self.list = DoublyLinkedList()
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def push(self, e):
        self.list.add_first(e)
        self.size += 1

    def pop(self):
        if self.is_empty():
            raise Empty("LinkedStack is empty")
        value = self.list.delete(self.list.first_node())
        self.size -= 1
        return value

    def top(self):
        if self.is_empty():
            raise Empty("LinkedStack is empty")
        value = self.list.first_node().data
        return value

class LeakyStack:
    def __init__(self, max_num_of_elems):
        self.list = DoublyLinkedList()
        self.capacity = max_num_of_elems

    def __len__(self):
        return len(self.list)

    def is_empty(self):
        return len(self.list) == 0

    def push(self, e):
        self.list.add_first(e)
        if len(self.list) > self.capacity:
            last_node = self.list.trailer.prev
            previous = last_node.prev
            previous.next = self.list.trailer
            self.list.trailer.prev = previous
            last_node.disconnect()

    def pop(self):
        if self.is_empty():
            raise Empty("LeakyStack is empty")
        value = self.list.delete(self.list.first_node())
        return value

    def top(self):
        if self.is_empty():
            raise Empty("LeakyStack is empty")
        value = self.list.first_node().data
        return value
