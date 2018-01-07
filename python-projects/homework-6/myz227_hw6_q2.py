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

class Integer:
    def __init__(self, num_str = None):
        self.elements = DoublyLinkedList()
        if num_str is None:
            pass
        else:
            for digit in num_str:
                self.elements.add_last(int(digit))

    def __add__(self, other):
        final_result = Integer()
        diff = abs(len(self.elements) - len(other.elements))
        for times in range(diff):
            if len(self.elements) < len(other.elements):
                self.elements.add_first(0)
            elif len(self.elements) > len(other.elements):
                other.elements.add_first(0)
        first_num = self.elements.last_node()
        second_num = other.elements.last_node()
        while first_num is not self.elements.header or second_num is not other.elements.header:
            temp_sum = int(first_num.data) + int(second_num.data)
            first_num = first_num.prev
            second_num = second_num.prev
            if temp_sum >= 10:
                final_result.elements.add_first(int(temp_sum % 10))
                if first_num is self.elements.header:
                    first_num = self.elements.add_first(0)
                    first_num.data = 1
                else:
                    first_num.data += 1
            else:
                final_result.elements.add_first(temp_sum)
        return final_result

    def __str__(self):
        string = ""
        for elem in self.elements:
            string += str(elem)
        return string

    def __repr__(self):
        return str(self.elements)