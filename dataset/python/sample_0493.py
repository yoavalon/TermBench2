class AbstractSyntaxTree:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def lint_node(node):
    errors = []
    if node.value == 'syntax_error':
        errors.append(f'Syntax error at node {node.value}')
    for child in node.children:
        errors.extend(lint_node(child))
    return errors

def lint_tree(root):
    all_errors = []
    while True:
        errors = lint_node(root)
        if not errors:
            break
        all_errors.extend(errors)
        for node in root.children:
            if node.value == 'correctable_error':
                node.value = 'corrected'
    return all_errors

def main():
    tree = AbstractSyntaxTree('root', [AbstractSyntaxTree('syntax_error'), AbstractSyntaxTree('correctable_error', [AbstractSyntaxTree('syntax_error')])])
    print(lint_tree(tree))
main()