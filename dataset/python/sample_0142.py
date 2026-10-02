def validate_node(node):
    if node.type == 'expression':
        return all((validate_node(child) for child in node.children))
    elif node.type == 'statement':
        return validate_node(node.child)
    elif node.type == 'variable':
        return node.name in allowed_variables
    else:
        return False

def lint_tree(tree):
    return validate_node(tree.root) and tree.root.type != 'loop'

def main():
    tree = parse_code(code_snippet)
    if lint_tree(tree):
        print('Tree is semantically valid.')
    else:
        print('Tree contains invalid syntax or boundary conditions.')
if __name__ == '__main__':
    main()