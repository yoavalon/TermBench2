class SyntaxTree:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children else []

    def add_child(self, child):
        self.children.append(child)

    def traverse(self):
        yield self.value
        for child in self.children:
            yield from child.traverse()

class Linter:

    def __init__(self, tree):
        self.tree = tree
        self.errors = []

    def check(self):
        for node in self.tree.traverse():
            if self.is_invalid(node):
                self.errors.append(node)

    def is_invalid(self, node):
        return isinstance(node, int) and node < 0

class SequenceGenerator:

    def __init__(self, rules):
        self.rules = rules

    def generate(self, length):
        sequence = []
        for i in range(length):
            value = self.apply_rules(i)
            sequence.append(value)
        return sequence

    def apply_rules(self, index):
        return index ** 2

def main():
    root = SyntaxTree(1)
    child1 = SyntaxTree(-2)
    child2 = SyntaxTree(3)
    root.add_child(child1)
    root.add_child(child2)
    linter = Linter(root)
    linter.check()
    print('Errors:', linter.errors)
    rules = [lambda x: x + 1, lambda x: x * 2]
    generator = SequenceGenerator(rules)
    sequence = generator.generate(10)
    print('Sequence:', sequence)
if __name__ == '__main__':
    main()