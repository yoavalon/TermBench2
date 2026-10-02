def lint_node(node):
    if isinstance(node, dict):
        for key, value in node.items():
            lint_node(value)
    elif isinstance(node, list):
        for item in node:
            lint_node(item)
    else:
        raise ValueError('Invalid node type')

def lint_tree(tree):
    while True:
        try:
            lint_node(tree)
        except ValueError as e:
            print(e)

def main():
    tree = {'root': [{'child1': 'data1'}, {'child2': [{'subchild1': 'data2'}, {'subchild2': 'data3'}]}]}
    lint_tree(tree)
main()