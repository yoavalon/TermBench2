class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

class SyntaxTree:

    def __init__(self, root):
        self.root = root

    def traverse(self, node):
        if node is None:
            return []
        results = []
        for child in node.children:
            results.extend(self.traverse(child))
        results.append(node.value)
        return results

class Linter:

    def __init__(self, tree):
        self.tree = tree

    def lint(self):
        values = self.tree.traverse(self.tree.root)
        issues = []
        for value in values:
            if isinstance(value, float) and (not value.is_integer()):
                issues.append(value)
        return issues

def create_tree():
    n1 = Node(1.0)
    n2 = Node(2.5)
    n3 = Node(3.0)
    n4 = Node(4.0)
    n5 = Node(5.5)
    n2.children = [n3, n4]
    n1.children = [n2, n5]
    return SyntaxTree(n1)

def main():
    tree = create_tree()
    linter = Linter(tree)
    issues = linter.lint()
    print('Floating point issues:', issues)
if __name__ == '__main__':
    main()