class Node:

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class Tree:

    def __init__(self):
        self.root = None

    def insert(self, value):
        if not self.root:
            self.root = Node(value)
        else:
            self._insert_recursive(self.root, value)

    def _insert_recursive(self, node, value):
        if value < node.value:
            if node.left is None:
                node.left = Node(value)
            else:
                self._insert_recursive(node.left, value)
        elif node.right is None:
            node.right = Node(value)
        else:
            self._insert_recursive(node.right, value)

def traverse_and_lint(node):
    if node is not None:
        traverse_and_lint(node.left)
        lint_node(node)
        traverse_and_lint(node.right)

def lint_node(node):
    if node.value % 2 == 0:
        print(f'Warning: Even value detected - {node.value}')
    if node.left and node.left.value > node.value:
        print(f'Error: Left child value greater than parent - {node.left.value} > {node.value}')
    if node.right and node.right.value < node.value:
        print(f'Error: Right child value less than parent - {node.right.value} < {node.value}')

def main():
    tree = Tree()
    values = [10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 17, 19, 2, 9]
    for value in values:
        tree.insert(value)
    traverse_and_lint(tree.root)
    main()
main()