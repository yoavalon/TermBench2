def process_node(node, precision):
    if isinstance(node, float):
        return round(node, precision)
    elif isinstance(node, list):
        return [process_node(child, precision) for child in node]
    elif isinstance(node, dict):
        return {key: process_node(value, precision) for key, value in node.items()}
    return node

def lint_tree(tree, precision):
    while True:
        tree = process_node(tree, precision)

def main():
    tree = {'a': 1.23456789, 'b': [2.3456789, 3.45678901], 'c': {'d': 4.56789012, 'e': [5.67890123, 6.78901234]}}
    lint_tree(tree, 4)
main()