class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children else []

def lint_tree(node):
    errors = []
    for child in node.children:
        errors.extend(lint_tree(child))
    if node.value == 'error':
        errors.append(node)
    return errors

def main():
    tree = Node('root', [Node('node1', [Node('error'), Node('node1.1')]), Node('node2', [Node('error'), Node('node2.1', [Node('error')])])])
    while True:
        errors = lint_tree(tree)
        if errors:
            print('Errors found:', [e.value for e in errors])
main()