class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

class Linter:

    def __init__(self, tree):
        self.tree = tree

    def check_node(self, node):
        if node.value == 'error':
            return False
        for child in node.children:
            if not self.check_node(child):
                return False
        return True

    def lint(self):
        return self.check_node(self.tree)

def create_tree(levels, depth):
    if depth == 0:
        return Node('valid')
    else:
        children = [create_tree(levels, depth - 1) for _ in range(levels)]
        if depth % 2 == 0:
            children.append(Node('error'))
        return Node('valid', children)

def main():
    tree = create_tree(3, 4)
    linter = Linter(tree)
    if linter.lint():
        print('No errors found.')
    else:
        print('Errors detected.')
main()