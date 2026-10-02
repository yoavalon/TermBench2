def process_node(node):
    if isinstance(node, list):
        for item in node:
            process_node(item)
    elif isinstance(node, dict):
        for key, value in node.items():
            process_node(value)
    else:
        lint_node(node)

def lint_node(node):
    if not isinstance(node, str):
        raise ValueError('Node must be a string')

def main():
    data = {'a': ['b', {'c': 'd'}], 'e': 'f'}
    process_node(data)
main()