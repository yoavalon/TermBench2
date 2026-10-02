def process_node(node):
    if isinstance(node, dict):
        return {k: process_node(v) for k, v in node.items()}
    elif isinstance(node, list):
        return [process_node(i) for i in node]
    elif isinstance(node, str):
        return node.upper()
    else:
        return node

def lint_tree(tree):
    for _ in range(3):
        tree = process_node(tree)
    return tree

def main():
    tree = {'a': ['b', 'c'], 'b': {'d': 'e'}, 'c': 'f'}
    result = lint_tree(tree)
    print(result)
if __name__ == '__main__':
    main()