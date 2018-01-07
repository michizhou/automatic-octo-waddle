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

class CompactString:
    def __init__(self, orig_str=None):
        self.elements = DoublyLinkedList()
        if orig_str is None:
            pass
        else:
            index = 0
            while index < len(orig_str):
                char = orig_str[index]
                count = 0
                while orig_str[index] == char and index < len(orig_str):
                    index += 1
                    count += 1
                self.elements.add_last((char, count))

    def __add__(self, other):
        old_end = self.elements.trailer.prev
        other.elements.header.next.prev = old_end
        old_end.next = other.elements.header.next
        self.elements.trailer.disconnect()
        other.elements.header.disconnect()
        return self.elements
    def __lt__(self, other):
        self_current = self.elements.header.next
        other_current = other.elements.header.next
        while ord(self_current.data[0]) == ord(other_current.data[0]):
            if self_current.data[1] == other_current.data[1]:
                if self_current.next is not None and other_current.next is not None:
                    self_current = self_current.next
                    other_current = other_current.next
                else:
                    return False
            elif self_current.data[1] < other_current.data[1]:
                if self_current.next is not None:
                    self_current = self_current.next
                else:
                    return True
            else:
                if other_current.next is not None:
                    other_current = other_current.next
                else:
                    return False
        if ord(self_current.data[0]) < ord(other_current.data[0]):
            return True
        else:
            return False
    def __le__(self, other):
        self_current = self.elements.header.next
        other_current = other.elements.header.next
        while ord(self_current.data[0]) == ord(other_current.data[0]):
            if self_current.data[1] == other_current.data[1]:
                if self_current.next is not None and other_current.next is not None:
                    self_current = self_current.next
                    other_current = other_current.next
                else:
                    return True
            elif self_current.data[1] < other_current.data[1]:
                if self_current.next is not None:
                    self_current = self_current.next
                else:
                    return True
            else:
                if other_current.next is not None:
                    other_current = other_current.next
                else:
                    return False
        if ord(self_current.data[0]) < ord(other_current.data[0]):
            return True
        else:
            return False

    def __gt__(self, other):
        self_current = self.elements.header.next
        other_current = other.elements.header.next
        while ord(self_current.data[0]) == ord(other_current.data[0]):
            if self_current.data[1] == other_current.data[1]:
                if self_current.next is not None and other_current.next is not None:
                    self_current = self_current.next
                    other_current = other_current.next
                else:
                    return False
            elif self_current.data[1] > other_current.data[1]:
                if self_current.next is not None:
                    self_current = self_current.next
                else:
                    return True
            else:
                if other_current.next is not None:
                    other_current = other_current.next
                else:
                    return False
        if ord(self_current.data[0]) > ord(other_current.data[0]):
            return True
        else:
            return False
    def __ge__(self, other):
        self_current = self.elements.header.next
        other_current = other.elements.header.next
        while ord(self_current.data[0]) == ord(other_current.data[0]):
            if self_current.data[1] == other_current.data[1]:
                if self_current.next is not None and other_current.next is not None:
                    self_current = self_current.next
                    other_current = other_current.next
                else:
                    return True
            elif self_current.data[1] > other_current.data[1]:
                if self_current.next is not None:
                    self_current = self_current.next
                else:
                    return True
            else:
                if other_current.next is not None:
                    other_current = other_current.next
                else:
                    return False
        if ord(self_current.data[0]) > ord(other_current.data[0]):
            return True
        else:
            return False
    def __str__(self):
        string = ""
        for elem in self.elements:
            for times in range(elem[1]):
                string += str(elem[0])
        return string
    def __repr__(self):
        return str(self)