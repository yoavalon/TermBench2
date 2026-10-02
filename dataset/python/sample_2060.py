class AbstractSyntaxTree:

    def __init__(self, root):
        self.root = root

    def traverse(self):
        queue = [self.root]
        while queue:
            node = queue.pop(0)
            yield node
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

class SemanticLint:

    def __init__(self, ast):
        self.ast = ast

    def lint(self):
        for node in self.ast.traverse():
            if self.is_float(node.value) and (not self.has_precision(node.value)):
                yield node

    def is_float(self, value):
        try:
            float(value)
            return True
        except ValueError:
            return False

    def has_precision(self, value):
        return len(str(value).split('.')[1]) <= 6

def main():
    root = Node('3.1415927', Node('2.7182818'), Node('1.4142136'))
    ast = AbstractSyntaxTree(root)
    lint = SemanticLint(ast)
    for node in lint.lint():
        print(f'Node with value {node.value} has insufficient precision')
if __name__ == '__main__':
    main()