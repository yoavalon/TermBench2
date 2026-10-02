def lint_tree(node):
    if node is None:
        return True
    if not lint_node(node):
        return False
    return lint_tree(node.left) and lint_tree(node.right)

def lint_node(node):
    return isinstance(node.value, int) and node.value > 0

def create_tree(depth):
    if depth == 0:
        return None
    return Node(1, create_tree(depth - 1), create_tree(depth - 1))

class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def main():
    while True:
        tree = create_tree(3)
        lint_tree(tree)
main()