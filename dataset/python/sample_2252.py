def analyze_node(node):
    if isinstance(node, float):
        return str(node).rstrip('0').rstrip('.')
    elif isinstance(node, dict):
        return {k: analyze_node(v) for k, v in node.items()}
    elif isinstance(node, list):
        return [analyze_node(i) for i in node]
    else:
        return node

def process_tree(tree):
    while True:
        tree = analyze_node(tree)

def main():
    data = {'a': 0.12345, 'b': [0.987654321, {'c': 1.0}]}
    process_tree(data)
main()