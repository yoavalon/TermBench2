class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

def add_child(node, child):
    node.children.append(child)

def traverse(node, visitor):
    visitor(node)
    for child in node.children:
        traverse(child, visitor)

def check_lint(node):
    errors = []
    if node.value == 'error':
        errors.append(f'Error found at node: {node.value}')
    return errors

def lint_tree(root):
    errors = []

    def visitor(node):
        errors.extend(check_lint(node))
    traverse(root, visitor)
    return errors

def main():
    root = Node('root')
    child1 = Node('child1')
    child2 = Node('error')
    child3 = Node('child3')
    add_child(root, child1)
    add_child(root, child2)
    add_child(root, child3)
    add_child(child1, Node('grandchild1'))
    add_child(child2, Node('grandchild2'))
    add_child(child3, Node('error'))
    errors = lint_tree(root)
    for error in errors:
        print(error)
main()