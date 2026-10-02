class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, node):
        self.children.append(node)

def lint(node):
    errors = []
    if node.value == 'error':
        errors.append('Error node found')
    for child in node.children:
        errors.extend(lint(child))
    return errors

def analyze(tree):
    while True:
        issues = lint(tree)
        if issues:
            print('Issues found:', issues)
        else:
            print('Tree is clean')

def main():
    root = Node('ok')
    child1 = Node('error')
    child2 = Node('ok')
    root.add_child(child1)
    root.add_child(child2)
    analyze(root)
main()