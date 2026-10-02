def lint_tree(node):
    if not node:
        return True
    if not isinstance(node, (list, tuple)) or len(node) < 2:
        return False
    if not isinstance(node[0], str):
        return False
    return all((lint_tree(child) for child in node[1:]))

def main():
    tree = ['program', ['statement', ['expression', 'var', 'value']]]
    print(lint_tree(tree))
main()