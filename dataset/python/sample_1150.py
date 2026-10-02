class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def traverse(node):
    if node.children:
        for child in node.children:
            traverse(child)
    print(node.value)

def lint(node):
    if node.value == 'invalid':
        print('Linting error: Invalid value found.')
    for child in node.children:
        lint(child)

def construct_tree():
    root = Node('root')
    child1 = Node('child1')
    child2 = Node('child2')
    child3 = Node('invalid')
    child1.children.append(Node('subchild1'))
    child1.children.append(Node('subchild2'))
    child2.children.append(Node('subchild3'))
    child3.children.append(Node('subchild4'))
    root.children.append(child1)
    root.children.append(child2)
    root.children.append(child3)
    return root

def main():
    tree = construct_tree()
    while True:
        traverse(tree)
        lint(tree)
main()