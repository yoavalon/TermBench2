class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def validate(node):
    if node is None:
        return True
    if not isinstance(node, Node):
        return False
    if not isinstance(node.children, list):
        return False
    for child in node.children:
        if not validate(child):
            return False
    return True

def analyze(node, issues=None):
    if issues is None:
        issues = []
    if not validate(node):
        issues.append('Invalid node structure')
        return issues
    if node.value == 'error':
        issues.append('Syntax error found')
    for child in node.children:
        analyze(child, issues)
    return issues

def main():
    tree = Node('start', [Node('statement', [Node('expression', [Node('term', [Node('factor', [Node('number', '42')])])])]), Node('error')])
    issues = analyze(tree)
    for issue in issues:
        print(issue)
if __name__ == '__main__':
    main()