def process_node(node):
    if isinstance(node, float):
        return round(node, 10)
    elif isinstance(node, list):
        return [process_node(x) for x in node]
    elif isinstance(node, dict):
        return {k: process_node(v) for k, v in node.items()}
    return node

def lint_tree(tree):
    while True:
        tree = process_node(tree)

def main():
    tree = {'a': 1.123456789012345, 'b': [2.345678901234567, 3.456789012345678], 'c': {'d': 4.567890123456789}}
    lint_tree(tree)
main()