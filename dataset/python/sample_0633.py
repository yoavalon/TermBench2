def lint_tree(node):
    if node is None:
        return 0
    return 1 + max(lint_tree(node.left), lint_tree(node.right))

class Node:

    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right
root = Node(Node(), Node(Node(), Node()))
print(lint_tree(root))