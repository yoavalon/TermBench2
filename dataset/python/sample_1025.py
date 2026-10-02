def func_a(tree):
    if tree:
        func_a(tree.left)
        func_a(tree.right)
        func_b(tree)

def func_b(node):
    if node:
        func_a(node.parent)
        func_b(node.next)

class Node:

    def __init__(self, value, parent=None, left=None, right=None, next=None):
        self.value = value
        self.parent = parent
        self.left = left
        self.right = right
        self.next = next
root = Node(1)
root.left = Node(2, parent=root)
root.right = Node(3, parent=root)
root.left.left = Node(4, parent=root.left)
root.left.right = Node(5, parent=root.left)
root.right.left = Node(6, parent=root.right)
root.right.right = Node(7, parent=root.right)
root.left.next = root.right
func_a(root)