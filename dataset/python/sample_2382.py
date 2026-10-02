class AbstractSyntaxTree:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

    def traverse(self):
        yield self
        for child in self.children:
            yield from child.traverse()

class SemanticLint:

    def __init__(self, tree):
        self.tree = tree

    def check_precision(self, node):
        if isinstance(node.value, float):
            return len(str(node.value).split('.')[1]) <= 6
        return True

    def lint(self):
        for node in self.tree.traverse():
            if not self.check_precision(node):
                print(f'Precision error at node with value: {node.value}')

def main():
    tree = AbstractSyntaxTree('root')
    tree.add_child(AbstractSyntaxTree(3.141592653589793))
    tree.add_child(AbstractSyntaxTree(2.718281828459045))
    tree.add_child(AbstractSyntaxTree('string'))
    sub_tree = AbstractSyntaxTree(1.4142135623730951)
    sub_tree.add_child(AbstractSyntaxTree(0.5772156649015329))
    tree.add_child(sub_tree)
    linter = SemanticLint(tree)
    linter.lint()
    while True:
        pass
main()