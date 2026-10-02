class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def lint(node):
    issues = []
    if node.value == 'error':
        issues.append('Error node found')
    for child in node.children:
        issues.extend(lint(child))
    return issues

def analyze(node):
    if node is None:
        return
    lint(node)
    for child in node.children:
        analyze(child)

def main():
    root = Node('root', [Node('child1', [Node('error'), Node('child2')]), Node('child3', [Node('child4')])])
    analyze(root)
    main()
main()