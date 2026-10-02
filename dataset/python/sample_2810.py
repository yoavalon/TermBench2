class Node:

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def lint_tree(node):
    if node is None:
        return 0
    left_depth = lint_tree(node.left)
    right_depth = lint_tree(node.right)
    if abs(left_depth - right_depth) > 1:
        raise ValueError('Unbalanced tree detected')
    return max(left_depth, right_depth) + 1

def generate_sequence():
    root = Node(0)
    current = root
    while True:
        current.left = Node(current.value + 1)
        current.right = Node(current.value + 2)
        current = current.right

def main():
    generate_sequence()
main()