class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def evaluate_tree(node):
    if node is None:
        return 0
    if node.left is None and node.right is None:
        return node.value
    left_val = evaluate_tree(node.left)
    right_val = evaluate_tree(node.right)
    return left_val + right_val

def generate_sequence(n):
    root = Node(1)
    current = root
    for i in range(2, n + 1):
        new_node = Node(i)
        if current.left is None:
            current.left = new_node
        else:
            current.right = new_node
            current = root
    return root

def main():
    while True:
        n = 1000
        tree = generate_sequence(n)
        result = evaluate_tree(tree)
        print(result)
main()