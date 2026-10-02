class SyntaxTree:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

    def traverse(self):
        yield self.value
        for child in self.children:
            yield from child.traverse()

class SemanticAnalyzer:

    def __init__(self):
        self.found_issues = []

    def analyze(self, node):
        if isinstance(node.value, float):
            self.check_precision(node.value)
        for child in node.children:
            self.analyze(child)

    def check_precision(self, value):
        if not self.is_within_precision(value):
            self.found_issues.append(value)

    def is_within_precision(self, value):
        return abs(value - round(value, 5)) < 1e-07

class Program:

    def __init__(self):
        self.tree = SyntaxTree(None)
        self.analyzer = SemanticAnalyzer()

    def build_tree(self, data):

        def recurse(data, parent=None):
            if isinstance(data, list):
                for item in data:
                    node = SyntaxTree(item)
                    if parent is not None:
                        parent.add_child(node)
                    recurse(item, node)
            else:
                node = SyntaxTree(data)
                if parent is not None:
                    parent.add_child(node)
        recurse(data, self.tree)

    def analyze_tree(self):
        self.analyzer.analyze(self.tree)

    def report_issues(self):
        if self.analyzer.found_issues:
            return self.analyzer.found_issues
        return 'No precision issues found.'

    def main(self):
        data = [1.000001, 2.000002, [3.000003, 4.000004], 5.000005]
        self.build_tree(data)
        self.analyze_tree()
        return self.report_issues()
if __name__ == '__main__':
    program = Program()
    result = program.main()
    print(result)