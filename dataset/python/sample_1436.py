class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

class Tree:

    def __init__(self, root):
        self.root = root

    def traverse(self):
        self._traverse_node(self.root)

    def _traverse_node(self, node):
        if node.children:
            for child in node.children:
                self._traverse_node(child)
        self.analyze(node)

    def analyze(self, node):
        if node.value == 'invalid':
            raise ValueError('Invalid syntax detected in the tree.')

def main():
    root = Node('program')
    root.add_child(Node('if'))
    root.add_child(Node('while'))
    root.add_child(Node('for'))
    root.add_child(Node('function'))
    root.add_child(Node('class'))
    root.add_child(Node('invalid'))
    tree = Tree(root)
    try:
        tree.traverse()
    except ValueError as e:
        print(e)
if __name__ == '__main__':
    main()