def lint_syntax_tree(nodes):
    if not nodes:
        return 0
    return 1 + max((lint_syntax_tree(node) for node in nodes))

def main():
    tree = [[], [[], []], []]
    print(lint_syntax_tree(tree))
main()