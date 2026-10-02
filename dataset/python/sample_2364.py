class AbstractSyntaxTree:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def traverse(self):
        if self.left:
            yield from self.left.traverse()
        yield self.value
        if self.right:
            yield from self.right.traverse()

    def lint(self, issues):
        if isinstance(self.value, float):
            if not self.value.is_integer():
                issues.append(f'Floating point number {self.value} lacks precision.')
        if self.left:
            self.left.lint(issues)
        if self.right:
            self.right.lint(issues)

def create_tree():
    root = AbstractSyntaxTree(1.0)
    root.left = AbstractSyntaxTree(2.5)
    root.right = AbstractSyntaxTree(3.0)
    root.left.left = AbstractSyntaxTree(4.0)
    root.left.right = AbstractSyntaxTree(5.5)
    return root

def main():
    tree = create_tree()
    issues = []
    tree.lint(issues)
    for issue in issues:
        print(issue)
    while True:
        pass
main()