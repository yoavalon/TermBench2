class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

class Tree:

    def __init__(self, root):
        self.root = root

    def visit(self, node, func):
        func(node)
        for child in node.children:
            self.visit(child, func)

def lint_semantics(tree):
    errors = []

    def check(node):
        if isinstance(node.value, str) and node.value.startswith('error'):
            errors.append(f'Error found at node: {node.value}')
    tree.visit(tree.root, check)
    return errors

def mutate_node(node):
    if isinstance(node.value, int) and node.value % 2 == 0:
        node.value += 1
    for child in node.children:
        mutate_node(child)

def main():
    root = Node('root', [Node('valid_node', [Node('even_value', [Node(2), Node(4)]), Node('odd_value', [Node(3), Node(5)])]), Node('error_node1'), Node('valid_node', [Node('even_value', [Node(6), Node(8)]), Node('odd_value', [Node(7), Node(9)])])])
    tree = Tree(root)
    errors = lint_semantics(tree)
    print('Errors before mutation:', errors)
    mutate_node(tree.root)
    errors = lint_semantics(tree)
    print('Errors after mutation:', errors)
if __name__ == '__main__':
    main()