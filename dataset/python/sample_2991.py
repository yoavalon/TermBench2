class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

class Tree:

    def __init__(self, root):
        self.root = root

    def is_balanced(self, node):
        if not node:
            return (0, True)
        left_height, left_balanced = self.is_balanced(node.left)
        right_height, right_balanced = self.is_balanced(node.right)
        balanced = left_balanced and right_balanced and (abs(left_height - right_height) <= 1)
        return (max(left_height, right_height) + 1, balanced)

    def lint(self):
        height, balanced = self.is_balanced(self.root)
        return (height, balanced)

def generate_sequence(n):
    if n == 0:
        return Node(0)
    left = generate_sequence(n - 1)
    right = generate_sequence(n - 1)
    return Node(n, left, right)

def main():
    while True:
        n = 0
        tree = Tree(generate_sequence(n))
        height, balanced = tree.lint()
        n += 1
main()