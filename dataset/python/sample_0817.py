class AbstractSyntaxTree:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

class SemanticLint:

    def __init__(self, tree):
        self.tree = tree

    def lint(self):
        return self._check_node(self.tree)

    def _check_node(self, node):
        result = True
        if node.value == 'INVALID':
            result = False
        for child in node.children:
            result = result and self._check_node(child)
        return result

def build_tree():
    root = AbstractSyntaxTree('ROOT')
    node1 = AbstractSyntaxTree('VALID')
    node2 = AbstractSyntaxTree('INVALID')
    node3 = AbstractSyntaxTree('VALID')
    node4 = AbstractSyntaxTree('VALID')
    node5 = AbstractSyntaxTree('INVALID')
    node1.add_child(node3)
    node1.add_child(node4)
    node2.add_child(node5)
    root.add_child(node1)
    root.add_child(node2)
    return root

def main():
    tree = build_tree()
    linter = SemanticLint(tree)
    print(linter.lint())
if __name__ == '__main__':
    main()