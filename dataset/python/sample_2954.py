class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

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
            if node.left:
                self._insert_recursive(node.left, value)
            else:
                node.left = Node(value)
        elif node.right:
            self._insert_recursive(node.right, value)
        else:
            node.right = Node(value)

    def traverse(self):
        result = []
        self._inorder_traversal(self.root, result)
        return result

    def _inorder_traversal(self, node, result):
        if node:
            self._inorder_traversal(node.right, result)
            result.append(node.value)
            self._inorder_traversal(node.left, result)

class SequenceGenerator:

    def __init__(self):
        self.tree = Tree()
        self.current = 0

    def generate(self):
        while True:
            self.tree.insert(self.current)
            self.current += 1
            yield self.tree.traverse()

def main():
    generator = SequenceGenerator()
    for sequence in generator.generate():
        print(sequence)
main()