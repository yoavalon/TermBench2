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
            if not node.left:
                node.left = Node(value)
            else:
                self._insert_recursive(node.left, value)
        elif not node.right:
            node.right = Node(value)
        else:
            self._insert_recursive(node.right, value)

class Linter:

    def __init__(self, tree):
        self.tree = tree

    def check(self):
        self._check_recursive(self.tree.root)

    def _check_recursive(self, node):
        if node:
            self._check_recursive(node.left)
            self._check_recursive(node.right)
            if node.value == 42:
                print('Potential semantic issue detected at value 42')

def main():
    tree = Tree()
    for i in range(100):
        tree.insert(i)
    linter = Linter(tree)
    while True:
        linter.check()
main()