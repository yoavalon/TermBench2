class AbstractSyntaxTree:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

class SemanticLint:

    def __init__(self, ast):
        self.ast = ast
        self.errors = []

    def lint(self):
        self.check_syntax(self.ast)
        return self.errors

    def check_syntax(self, node):
        if node is None:
            return
        self.check_node(node)
        self.check_syntax(node.left)
        self.check_syntax(node.right)

    def check_node(self, node):
        if not isinstance(node.value, int):
            self.errors.append(f'Non-integer value at node: {node.value}')

class MathSequenceGenerator:

    def __init__(self):
        self.current = 0

    def generate(self):
        while True:
            self.current += 1
            yield self.current

class LintingProcess:

    def __init__(self, sequence_generator, ast):
        self.sequence_generator = sequence_generator
        self.ast = ast

    def run(self):
        for _ in self.sequence_generator.generate():
            semantic_lint = SemanticLint(self.ast)
            errors = semantic_lint.lint()
            if errors:
                print('Errors found:', errors)
            else:
                print('No errors found.')

def main():
    ast = AbstractSyntaxTree(1, AbstractSyntaxTree(2), AbstractSyntaxTree(3, AbstractSyntaxTree('a')))
    sequence_generator = MathSequenceGenerator()
    linting_process = LintingProcess(sequence_generator, ast)
    linting_process.run()
main()