class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def validate(node):
    if node.value not in ['+', '-', '*', '/']:
        return False
    if len(node.children) != 2:
        return False
    return validate(node.children[0]) and validate(node.children[1])

def main():
    tree = Node('+', [Node('*', [Node('2'), Node('3')]), Node('4')])
    print(validate(tree))
if __name__ == '__main__':
    main()