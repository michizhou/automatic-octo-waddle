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

class LinkedBinaryTree:
    class Node:
        def __init__(self, data, left=None, right=None):
            self.data = data
            self.left = left
            if (self.left is not None):
                self.left.parent = self
            self.right = right
            if (self.right is not None):
                self.right.parent = self
            self.parent = None

    def __init__(self, root=None):
        self.root = root
        self.size = self.subtree_count(self.root)

    def __len__(self):
        return self.size

    def is_empty(self):
        return (len(self) == 0)

    def subtree_count(self, subtree_root):
        if(subtree_root is None):
            return 0
        else:
            left_count = self.subtree_count(subtree_root.left)
            right_count = self.subtree_count(subtree_root.right)
            return left_count + right_count + 1


    def sum_tree(self):
        return self.subtree_sum(self.root)

    def subtree_sum(self, subtree_root):
        if(subtree_root is None):
            return 0
        else:
            left_sum = self.subtree_sum(subtree_root.left)
            right_sum = self.subtree_sum(subtree_root.right)
            return left_sum + right_sum + subtree_root.data

    def height(self):
        if (self.is_empty()):
            raise Empty("Height is not defined for an empty tree")
        return self.subtree_height(self.root)

    #assuming subtree_root is not empty
    def subtree_height(self, subtree_root):
        if((subtree_root.left is None) and (subtree_root.right is None)):
            return 0
        elif(subtree_root.left is None):
            return 1 + self.subtree_height(subtree_root.right)
        elif(subtree_root.right is None):
            return 1 + self.subtree_height(subtree_root.left)
        else:
            left_height = self.subtree_height(subtree_root.left)
            right_height = self.subtree_height(subtree_root.right)
            return 1 + max(left_height, right_height)


    def preorder(self):
        yield from self.subtree_preorder(self.root)

    def subtree_preorder(self, subtree_root):
        if(subtree_root is None):
            return
        else:
            yield subtree_root
            yield from self.subtree_preorder(subtree_root.left)
            yield from self.subtree_preorder(subtree_root.right)


    def postorder(self):
        yield from self.subtree_postorder(self.root)

    def subtree_postorder(self, subtree_root):
        if(subtree_root is None):
            return
        else:
            yield from self.subtree_postorder(subtree_root.left)
            yield from self.subtree_postorder(subtree_root.right)
            yield subtree_root


    def inorder(self):
        yield from self.subtree_inorder(self.root)

    def subtree_inorder(self, subtree_root):
        if(subtree_root is None):
            return
        else:
            yield from self.subtree_inorder(subtree_root.left)
            yield subtree_root
            yield from self.subtree_inorder(subtree_root.right)


    def __iter__(self):
        for node in self.inorder():
            yield node.data


    def breadth_first(self):
        if(self.is_empty()):
            return
        nodes_q = ArrayQueue.ArrayQueue()
        nodes_q.enqueue(self.root)
        while(nodes_q.is_empty() == False):
            curr_node = nodes_q.dequeue()
            yield curr_node
            if (curr_node.left is not None):
                nodes_q.enqueue(curr_node.left)
            if (curr_node.right is not None):
                nodes_q.enqueue(curr_node.right)

    def leaves_list(self):          #Question 2
        leaves = []
        def get_leaves(node):
            if node is not None:
                if node.left is None and node.right is None:
                    leaves.append(node.data)
                get_leaves(node.left)
                get_leaves(node.right)
        get_leaves(self.root)
        return leaves

    def iterative_inorder(self):        #Question 4
        current = self.root
        while current is not None:
            if current.left is None:
                yield current.data
                current = current.right
            else:
                previous = current.left
                while previous.right is not None and previous.right != current:
                    previous = previous.right
                if previous.right is None:
                    previous.right = current
                    current = current.left
                else:
                    previous.right = None
                    yield current.data
                    current = current.right

#Flattens a nested doubly linked list of integers
def flattened_linked_lst(lnk_lst):
    new_lst = DoublyLinkedList()
    for element in lnk_lst:
        if isinstance(element, int):
            new_lst.add_last(element)
        else:
            for item in flattened_linked_lst(element):
                new_lst.add_last(item)
    return new_lst



#Recursive implementation of function that inverts a binary tree
def invertTree(bin_tree):
    if bin_tree.root is None:
        return None
    left_tree = invertTree(LinkedBinaryTree(bin_tree.root.left))
    right_tree = invertTree(LinkedBinaryTree(bin_tree.root.right))
    bin_tree.root.left, bin_tree.root.right = right_tree.root, left_tree.root
    return bin_tree

# BFS implementation for inverting a binary tree
def invertTree2(self, root):
    queue = collections.deque([(root)])
    while queue:
        node = queue.popleft()
        if node:
            node.left, node.right = node.right, node.left
            queue.append(node.left)
            queue.append(node.right)
    return root

# DFS implementation for inverting a binary tree
def invertTree3(self, root):
    stack = [root]
    while stack:
        node = stack.pop()
        if node:
            node.left, node.right = node.right, node.left
            stack.extend([node.right, node.left])
    return root



#Flattens binary tree to a linked list in-place
def flatten(bin_tree):
    return flattenRecu(bin_tree.root, None)

def flattenRecu(root, list_head):
    if root != None:
        list_head = flattenRecu(root.right, list_head)
        list_head = flattenRecu(root.left, list_head)
        root.right = list_head
        root.left = None
        return root
    else:
        return list_head
