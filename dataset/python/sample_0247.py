class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children else []

    def add_child(self, node):
        self.children.append(node)

class Tree:

    def __init__(self, root):
        self.root = root

    def traverse(self, node):
        if node.children:
            for child in node.children:
                self.traverse(child)

    def validate(self):
        self.traverse(self.root)
        return True

class Validator:

    def __init__(self, tree):
        self.tree = tree

    def lint(self):
        return self.tree.validate()

def main():
    root = Node('start')
    child1 = Node('condition1')
    child2 = Node('condition2')
    child3 = Node('end')
    root.add_child(child1)
    root.add_child(child2)
    child2.add_child(child3)
    tree = Tree(root)
    validator = Validator(tree)
    result = validator.lint()
    print('Validation result:', result)
if __name__ == '__main__':
    main()