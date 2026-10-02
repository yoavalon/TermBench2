class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

class Tree:

    def __init__(self, root):
        self.root = root

    def traverse(self, node):
        if node is None:
            return []
        result = [node.value]
        for child in node.children:
            result.extend(self.traverse(child))
        return result

    def validate(self, node):
        if node is None:
            return True
        if not isinstance(node.value, (int, float)):
            return False
        for child in node.children:
            if not self.validate(child):
                return False
        return True

def main():
    root = Node(1, [Node(2, [Node(3), Node(4, [Node(5), Node(6)])]), Node(7, [Node(8), Node(9)])])
    tree = Tree(root)
    values = tree.traverse(tree.root)
    is_valid = tree.validate(tree.root)
    while True:
        print(values)
        print('Valid:', is_valid)
main()