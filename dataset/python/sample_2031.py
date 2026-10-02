class SyntaxTree:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

    def validate(self):
        result = []
        for child in self.children:
            result.extend(child.validate())
        if self.value == 'FloatingPointOperation':
            result.extend(self.check_precision())
        return result

    def check_precision(self):
        issues = []
        for child in self.children:
            if child.value == 'PrecisionLoss':
                issues.append(f'Precision loss detected in {self.value}')
        return issues

class PrecisionChecker:

    def __init__(self, tree):
        self.tree = tree

    def lint(self):
        return self.tree.validate()

class ReportGenerator:

    def __init__(self, issues):
        self.issues = issues

    def generate(self):
        if not self.issues:
            return 'No precision issues detected.'
        return '\n'.join(self.issues)

def main():
    root = SyntaxTree('Program')
    function = SyntaxTree('Function')
    operation = SyntaxTree('FloatingPointOperation')
    precision_loss = SyntaxTree('PrecisionLoss')
    operation.add_child(precision_loss)
    function.add_child(operation)
    root.add_child(function)
    checker = PrecisionChecker(root)
    issues = checker.lint()
    reporter = ReportGenerator(issues)
    print(reporter.generate())
if __name__ == '__main__':
    main()