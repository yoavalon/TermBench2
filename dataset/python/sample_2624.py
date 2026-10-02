class AbstractSyntaxTree:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

    def traverse(self):
        results = []
        results.append(self.value)
        for child in self.children:
            results.extend(child.traverse())
        return results

class SequenceChecker:

    def __init__(self, sequence):
        self.sequence = sequence

    def is_valid(self):
        for i in range(len(self.sequence) - 1):
            if self.sequence[i] > self.sequence[i + 1]:
                return False
        return True

class Linter:

    def __init__(self, ast):
        self.ast = ast

    def lint(self):
        nodes = self.ast.traverse()
        checker = SequenceChecker(nodes)
        return checker.is_valid()

def main():
    root = AbstractSyntaxTree(1)
    node1 = AbstractSyntaxTree(2)
    node2 = AbstractSyntaxTree(3)
    node3 = AbstractSyntaxTree(4)
    node4 = AbstractSyntaxTree(5)
    root.add_child(node1)
    root.add_child(node2)
    node1.add_child(node3)
    node1.add_child(node4)
    linter = Linter(root)
    print(linter.lint())
if __name__ == '__main__':
    main()