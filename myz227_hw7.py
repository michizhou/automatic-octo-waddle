class Empty(Exception):
    pass

class EmptyTree(Exception):
    pass

class ArrayQueue:
    INIT_CAPACITY = 10

    def __init__(self):
        self.data = [None] * ArrayQueue.INIT_CAPACITY
        self.front_ind = 0
        self.num_of_elems = 0

    def __len__(self):
        return self.num_of_elems

    def is_empty(self):
        return (len(self) == 0)

    def enqueue(self, elem):
        if (self.num_of_elems == len(self.data)):
            self.resize(2 * len(self.data))
        back_ind = (self.front_ind + self.num_of_elems) % len(self.data)
        self.data[back_ind] = elem
        self.num_of_elems += 1

    def dequeue(self):
        if (self.is_empty()):
            raise Empty("Queue is empty")
        elem = self.data[self.front_ind]
        self.data[self.front_ind] = None
        self.front_ind = (self.front_ind + 1) % len(self.data)
        self.num_of_elems -= 1
        if (self.num_of_elems < len(self.data) // 4):
            self.resize(len(self.data) // 2)
        return elem

    def front(self):
        if (self.is_empty()):
            raise Empty("Queue is empty")
        return self.data[self.front_ind]

    def resize(self, new_capacity):
        old_data = self.data
        self.data = [None] * new_capacity
        old_ind = self.front_ind
        for new_ind in range(self.num_of_elems):
            self.data[new_ind] = old_data[old_ind]
            old_ind = (old_ind + 1) % len(old_data)
        self.front_ind = 0

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

def min_and_max(bin_tree):
    if bin_tree.root is None:
        raise EmptyTree("Tree has no nodes")
    return subtree_min_and_max(bin_tree, bin_tree.root)

def subtree_min_and_max(bin_tree, sub_tree_root):
    import math
    if sub_tree_root is None:
        return (math.inf,-math.inf)
    min_value, max_value = sub_tree_root.data, sub_tree_root.data
    left_values = subtree_min_and_max(bin_tree, sub_tree_root.left)
    right_values = subtree_min_and_max(bin_tree, sub_tree_root.right)
    branch_min = min(left_values[0], right_values[0])
    branch_max = max(left_values[1], right_values[1])
    if branch_min < min_value:
        min_value = branch_min
    if branch_max > max_value:
        max_value = branch_max
    return (min_value, max_value)


def is_height_balanced(bin_tree):
    values = sub_balanced(bin_tree.root)
    return values[1]

def sub_balanced(node):
    if node is None:
        return (0, True)
    else:
        left_tree = sub_balanced(node.left)
        right_tree = sub_balanced(node.right)
        height = 1 + max(left_tree[0], right_tree[0])
        if left_tree[1] is True and right_tree[1] is True:
            if abs(left_tree[0]-right_tree[0]) > 1:
                return (height, False)
            else:
                return (height, True)
        else:
            return (height, False)


def create_expression_tree(prefix_exp_str):
    exp_lst = prefix_exp_str.split(" ")
    tree_tuple = create_expression_tree_helper(exp_lst, 0)
    final_tree = LinkedBinaryTree(tree_tuple[0])
    return final_tree

def create_expression_tree_helper(prefix_exp, start_pos):
    exp_tree = LinkedBinaryTree()
    value = prefix_exp[start_pos]
    if value.isdigit():
        exp_tree.root = exp_tree.Node(int(value))
        return (exp_tree.root, start_pos + 1)
    else:
        left_tree = create_expression_tree_helper(prefix_exp, start_pos + 1)
        right_tree = create_expression_tree_helper(prefix_exp, left_tree[1])
        return (exp_tree.Node(str(value), left_tree[0], right_tree[0]), right_tree[1])

def prefix_to_postfix(prefix_exp_str):
    stack_lst = []
    exp_lst = prefix_exp_str.split(" ")
    for item in reversed(exp_lst):
        if item.isdigit():
            stack_lst.append(item)
        else:
            first_value = stack_lst.pop()
            second_value = stack_lst.pop()
            new_seq = str(first_value) + " " + str(second_value) + " " + str(item)
            stack_lst.append(new_seq)
    final_str = ' '.join(reversed(stack_lst))
    return final_str