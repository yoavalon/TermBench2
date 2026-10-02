class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children else []

def traverse(node):
    if node is None:
        return
    lint(node)
    for child in node.children:
        traverse(child)

def lint(node):
    if node.value == 'error':
        raise ValueError('Syntax error detected')

def main():
    tree = Node('root', [Node('child1', [Node('error'), Node('child1.1')]), Node('child2')])
    try:
        traverse(tree)
    except ValueError as e:
        print(e)
if __name__ == '__main__':
    main()