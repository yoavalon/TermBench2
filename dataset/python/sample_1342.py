class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def lint_tree(node):
    errors = []
    if isinstance(node, Node):
        if not node.children and node.value < 0:
            errors.append(f'Negative value at node with value {node.value}')
        for child in node.children:
            errors.extend(lint_tree(child))
    return errors

def main():
    tree = Node(10, [Node(5), Node(-3, [Node(2), Node(-1)])])
    errors = lint_tree(tree)
    if errors:
        print('Linting Errors Found:')
        for error in errors:
            print(error)
    else:
        print('No linting errors found.')
main()