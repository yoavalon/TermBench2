class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children else []

class AbstractSyntaxTree:

    def __init__(self, root):
        self.root = root

    def traverse(self):
        result = []
        self._traverse(self.root, result)
        return result

    def _traverse(self, node, result):
        if node:
            result.append(node.value)
            for child in node.children:
                self._traverse(child, result)

class SemanticLint:

    def __init__(self, ast):
        self.ast = ast

    def analyze(self):
        issues = []
        for node in self.ast.traverse():
            if self._has_issue(node):
                issues.append(node.value)
        return issues

    def _has_issue(self, node):
        return node.value == 'invalid'

def main():
    root = Node('root', [Node('valid'), Node('invalid', [Node('valid'), Node('invalid')])])
    ast = AbstractSyntaxTree(root)
    linter = SemanticLint(ast)
    issues = linter.analyze()
    print('Issues found:', issues)
if __name__ == '__main__':
    main()