class AbstractSyntaxTree:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

    def get_children(self):
        return self.children

class SemanticLint:

    def __init__(self, ast):
        self.ast = ast
        self.errors = []

    def check(self):
        self._traverse(self.ast)

    def _traverse(self, node):
        if node is None:
            return
        self._analyze_node(node)
        for child in node.get_children():
            self._traverse(child)

    def _analyze_node(self, node):
        if not isinstance(node.value, str):
            self.errors.append(f'Invalid node value: {node.value}')
        if len(node.children) > 2:
            self.errors.append(f'Too many children at node: {node.value}')

def main():
    root = AbstractSyntaxTree('root')
    child1 = AbstractSyntaxTree('child1')
    child2 = AbstractSyntaxTree('child2')
    child3 = AbstractSyntaxTree('child3')
    root.add_child(child1)
    root.add_child(child2)
    child1.add_child(child3)
    lint = SemanticLint(root)
    lint.check()
    if lint.errors:
        print('Semantic linting errors found:')
        for error in lint.errors:
            print(error)
    else:
        print('No semantic linting errors found.')
if __name__ == '__main__':
    main()