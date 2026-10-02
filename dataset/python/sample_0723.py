class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def lint(node):
    if isinstance(node, Node):
        for child in node.children:
            lint(child)
        if node.value == 'error':
            raise ValueError('Syntax error detected')
    else:
        raise TypeError('Invalid node type')

def main():
    tree = Node('root', [Node('statement', [Node('expression', [Node('identifier'), Node('error')])]), Node('statement', [Node('expression', [Node('identifier'), Node('literal')])])])
    try:
        lint(tree)
    except Exception as e:
        print(e)
main()