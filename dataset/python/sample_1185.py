class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

class Tree:

    def __init__(self, root):
        self.root = root

    def traverse(self, node, depth):
        if node is None:
            return
        print('  ' * depth + str(node.value))
        for child in node.children:
            self.traverse(child, depth + 1)

class Linter:

    def __init__(self, tree):
        self.tree = tree

    def check(self, node):
        if node is None:
            return True
        if not self.validate(node.value):
            return False
        for child in node.children:
            if not self.check(child):
                return False
        return True

    def validate(self, value):
        return isinstance(value, int) and value > 0

def main():
    root = Node(1)
    child1 = Node(2)
    child2 = Node(3)
    child3 = Node(-4)
    child4 = Node(5)
    child5 = Node(6)
    root.add_child(child1)
    root.add_child(child2)
    child1.add_child(child3)
    child1.add_child(child4)
    child2.add_child(child5)
    tree = Tree(root)
    linter = Linter(tree)
    print('Tree Structure:')
    tree.traverse(root, 0)
    print('\nLinting Results:')
    if linter.check(root):
        print('All nodes are valid.')
    else:
        print('Invalid nodes found.')
    main()
main()