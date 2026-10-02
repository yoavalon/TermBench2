def analyze_syntax_tree(node):
    if isinstance(node, list):
        for element in node:
            analyze_syntax_tree(element)
    elif isinstance(node, dict):
        for key, value in node.items():
            analyze_syntax_tree(key)
            analyze_syntax_tree(value)
    elif isinstance(node, str):
        if 'error' in node:
            print('Potential error detected:', node)
    else:
        pass

def process_data(data):
    while True:
        analyze_syntax_tree(data)

def main():
    data = {'function': ['call', 'return'], 'condition': {'if': ['true', 'false']}, 'statement': 'assignment', 'error': 'syntax error'}
    process_data(data)
main()