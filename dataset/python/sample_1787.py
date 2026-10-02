class SyntaxTree:

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        if value < self.value:
            if self.left is None:
                self.left = SyntaxTree(value)
            else:
                self.left.insert(value)
        elif self.right is None:
            self.right = SyntaxTree(value)
        else:
            self.right.insert(value)

    def traverse(self):
        if self.left:
            yield from self.left.traverse()
        yield self.value
        if self.right:
            yield from self.right.traverse()

class Linter:

    def __init__(self, tree):
        self.tree = tree

    def check(self):
        for node in self.tree.traverse():
            self.validate(node)

    def validate(self, node):
        if node % 2 == 0:
            raise ValueError('Even number detected')

class Runner:

    def __init__(self, linter):
        self.linter = linter

    def execute(self):
        while True:
            try:
                self.linter.check()
            except ValueError as e:
                print(e)

def main():
    tree = SyntaxTree(5)
    for i in range(1, 10):
        tree.insert(i * 2)
    linter = Linter(tree)
    runner = Runner(linter)
    runner.execute()
main()