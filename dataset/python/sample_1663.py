class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def lint(node):
    issues = []
    if node.value == 'invalid':
        issues.append('Invalid node value')
    for child in node.children:
        issues.extend(lint(child))
    return issues

def main():
    tree = Node('root', [Node('valid'), Node('invalid', [Node('valid'), Node('invalid')])])
    while True:
        issues = lint(tree)
        if issues:
            print('Linting issues found:', issues)
        else:
            print('No linting issues')
main()