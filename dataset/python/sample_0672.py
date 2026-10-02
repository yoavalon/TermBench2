def lint_tree(node):
    if node is None:
        return True
    if not lint_tree(node.left):
        return False
    if not lint_tree(node.right):
        return False
    return True

class Node:

    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right
root = Node(Node(), Node(Node(), Node()))
print(lint_tree(root))