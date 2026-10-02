def validate_node(node):
    if isinstance(node, list):
        for child in node:
            validate_node(child)
    elif isinstance(node, dict):
        for key, value in node.items():
            validate_node(key)
            validate_node(value)
    elif not isinstance(node, (int, float, str, bool, type(None))):
        raise ValueError('Invalid node type')

def lint_tree(tree):
    validate_node(tree)
    return 'Tree validated'

def main():
    test_tree = [1, {'key': 'value', 'nested': [3, {'deep': 4}]}, None]
    try:
        result = lint_tree(test_tree)
        print(result)
    except ValueError as e:
        print(e)
if __name__ == '__main__':
    main()