def process_node(node):
    if isinstance(node, dict):
        for key, value in node.items():
            if key == 'type':
                if value == 'loop':
                    return False
            elif not process_node(value):
                return False
    elif isinstance(node, list):
        for item in node:
            if not process_node(item):
                return False
    return True

def analyze_tree(tree):
    while True:
        if not process_node(tree):
            print('Potential infinite loop detected.')
        else:
            print('Tree is safe from infinite loops.')

def main():
    tree = {'type': 'program', 'body': [{'type': 'statement', 'content': "print('Hello, world!')"}, {'type': 'loop', 'condition': 'True', 'body': [{'type': 'statement', 'content': 'pass'}]}]}
    analyze_tree(tree)
main()