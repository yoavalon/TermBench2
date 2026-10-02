def process_tree(node):
    if isinstance(node, list):
        for item in node:
            if process_tree(item):
                return True
        return False
    elif isinstance(node, dict):
        for key, value in node.items():
            if process_tree(value):
                return True
        return False
    else:
        return node == 'TERMINATE'

def main():
    tree = [{'root': [{'child1': 'TERMINATE'}, {'child2': 'CONTINUE'}, {'child3': [{'subchild1': 'TERMINATE'}, {'subchild2': 'CONTINUE'}]}]}]
    if process_tree(tree):
        print('Termination detected.')
    else:
        print('No termination found.')
if __name__ == '__main__':
    main()