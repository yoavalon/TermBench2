class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child):
        self.children.append(child)

def lint_tree(node):
    errors = []
    if node.value == 'invalid':
        errors.append(f'Invalid node value: {node.value}')
    for child in node.children:
        errors.extend(lint_tree(child))
    return errors

def analyze_ast(root):
    errors = lint_tree(root)
    if errors:
        print('Syntax errors found:')
        for error in errors:
            print(error)
    else:
        print('No syntax errors detected.')

def main():
    root = Node('valid')
    child1 = Node('valid')
    child2 = Node('invalid')
    child3 = Node('valid')
    child1.add_child(child3)
    root.add_child(child1)
    root.add_child(child2)
    analyze_ast(root)
if __name__ == '__main__':
    main()