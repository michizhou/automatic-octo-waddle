class BinarySearchTreeMap:

    class Item:
        def __init__(self, key, value=None):
            self.key = key
            self.value = value


    class Node:
        def __init__(self, item):
            self.item = item
            self.count = 0
            self.parent = None
            self.left = None
            self.right = None

        def num_children(self):
            count = 0
            if (self.left is not None):
                count += 1
            if (self.right is not None):
                count += 1
            return count

        def disconnect(self):
            self.item = None
            self.parent = None
            self.left = None
            self.right = None


    def __init__(self):
        self.root = None
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return len(self) == 0


    # raises exception if not found
    def __getitem__(self, key):
        node = self.subtree_find(self.root, key)
        if (node is None):
            raise KeyError(str(key) + " not found")
        else:
            return node.item.value

    # returns None if not found
    def subtree_find(self, subtree_root, key):
        curr = subtree_root
        while (curr is not None):
            if (curr.item.key == key):
                return curr
            elif (curr.item.key > key):
                curr = curr.left
            else:  # (curr.item.key < key)
                curr = curr.right
        return None


    # updates value if key already exists
    def __setitem__(self, key, value):
        node = self.subtree_find(self.root, key)
        if (node is None):
            self.subtree_insert(key, value)
        else:
            node.item.value = value

    # assumes key not in tree
    def subtree_insert(self, key, value=None):
        item = BinarySearchTreeMap.Item(key, value)
        new_node = BinarySearchTreeMap.Node(item)
        if (self.is_empty()):
            self.root = new_node
            self.size = 1
        else:
            parent = self.root
            curr = self.root
            while (curr is not None):
                parent = curr
                if (key < curr.item.key):
                    curr.count += 1
                    parent.count = curr.count
                    curr = curr.left
                else:
                    curr = curr.right
            if (key < parent.item.key):
                parent.left = new_node
            else:
                parent.right = new_node
            new_node.parent = parent
            new_node.count = new_node.parent.count + 1
            self.size += 1


    #raises exception if key not in tree
    def __delitem__(self, key):
        if (self.subtree_find(self.root, key) is None):
            raise KeyError(str(key) + " is not found")
        else:
            self.subtree_delete(self.root, key)

    #assumes key is in tree + returns value assosiated
    def subtree_delete(self, node, key):
        node_to_delete = self.subtree_find(node, key)
        value = node_to_delete.item.value
        num_children = node_to_delete.num_children()

        if (node_to_delete is self.root):
            if (num_children == 0):
                self.root = None
                node_to_delete.disconnect()
                self.size -= 1

            elif (num_children == 1):
                if (self.root.left is not None):
                    self.root = self.root.left
                else:
                    self.root = self.root.right
                self.root.parent = None
                node_to_delete.disconnect()
                self.size -= 1

            else: #num_children == 2
                max_of_left = self.subtree_max(node_to_delete.left)
                node_to_delete.item = max_of_left.item
                self.subtree_delete(node_to_delete.left, max_of_left.item.key)

        else:
            if (num_children == 0):
                parent = node_to_delete.parent
                if (node_to_delete is parent.left):
                    parent.left = None
                else:
                    parent.right = None

                node_to_delete.disconnect()
                self.size -= 1

            elif (num_children == 1):
                parent = node_to_delete.parent
                if(node_to_delete.left is not None):
                    child = node_to_delete.left
                else:
                    child = node_to_delete.right

                child.parent = parent
                if (node_to_delete is parent.left):
                    parent.left = child
                else:
                    parent.right = child

                node_to_delete.disconnect()
                self.size -= 1

            else: #num_children == 2
                max_of_left = self.subtree_max(node_to_delete.left)
                node_to_delete.item = max_of_left.item
                self.subtree_delete(node_to_delete.left, max_of_left.item.key)

        return value

    # assumes non empty subtree
    def subtree_max(self, curr_root):
        node = curr_root
        while (node.right is not None):
            node = node.right
        return node


    def inorder(self):
        for node in self.subtree_inorder(self.root):
            yield node

    def subtree_inorder(self, curr_root):
        if(curr_root is None):
            pass
        else:
            yield from self.subtree_inorder(curr_root.left)
            yield curr_root
            yield from self.subtree_inorder(curr_root.right)

    def preorder(self):
        for node in self.subtree_preorder(self.root):
            yield node

    def subtree_preorder(self, curr_root):
        if(curr_root is None):
            pass
        else:
            yield curr_root
            yield from self.subtree_preorder(curr_root.left)
            yield from self.subtree_preorder(curr_root.right)

    def __iter__(self):
        for node in self.inorder():
            yield (node.item.key, node.item.value)

    def get_ith_smallest(self, i):
        if i > len(self) or i < 1:
            raise IndexError("Index is out of bounds")
        else:
            result = 0
            traverse_node = self.root
            while traverse_node is not None:
                if (traverse_node.count + 1) == i:
                    result = traverse_node.item.key
                    return result
                elif i > traverse_node.count:
                    i = i - (traverse_node.count + 1)
                    traverse_node = traverse_node.right
                else:
                    traverse_node = traverse_node.left
            return result


def create_chain_bst(n):
    new_bst = BinarySearchTreeMap()
    for num in range(1, n+1):
        new_bst.subtree_insert(num)
    return new_bst

def create_complete_bst(n):
    bst = BinarySearchTreeMap()
    add_items(bst, 1, n)
    return bst

def add_items(bst, low, high):
    if low <= high:
        mid_value = (low + high) // 2
        root_item = BinarySearchTreeMap.Item(mid_value)
        bst.root = BinarySearchTreeMap.Node(root_item)
        left_tree = BinarySearchTreeMap()
        right_tree = BinarySearchTreeMap()
        add_items(left_tree, low, mid_value - 1)
        add_items(right_tree, mid_value + 1, high)
        bst.root.left = left_tree.root
        bst.root.right = right_tree.root
    else:
        return


def restore_bst(prefix_lst):
    new_bst = BinarySearchTreeMap()
    construct_bst.curr_index = 0
    num_nodes = len(prefix_lst)
    if num_nodes > 0:
        new_bst.root = construct_bst(prefix_lst, prefix_lst[0], float("-infinity"), float("infinity"), num_nodes)
    return new_bst

def getCurrIndex():
    return construct_bst.curr_index

def incrementCurrIndex():
    construct_bst.curr_index += 1

def construct_bst(prefix, key, low, high, size):
    if getCurrIndex() >= size or key < low or key > high:
        return None
    else:
        pre_item = BinarySearchTreeMap.Item(key)
        root = BinarySearchTreeMap.Node(pre_item)
        incrementCurrIndex()
        if getCurrIndex() < size:
            root.left = construct_bst(prefix, prefix[getCurrIndex()], low, key, size)
            root.right = construct_bst(prefix, prefix[getCurrIndex()], key, high, size)
        return root


def find_min_abs_difference(bst):
    def traversal(node, lst=[]):
        if node.left:
            traversal(node.left, lst)
        lst.append(node.item.key)
        if node.right:
            traversal(node.right, lst)
        return lst
    lst = traversal(bst.root)
    return min([abs(a-b) for a,b in zip(lst, lst[1:])])