def lint_tree(node):
    if node:
        lint_tree(node.left)
        lint_tree(node.right)
        lint_tree(node)

class Node:

    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right
root = Node(Node(), Node(Node()))
lint_tree(root)