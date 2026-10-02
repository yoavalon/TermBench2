class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def lint(node):
    if node is None:
        return True
    if not (node.left is None or isinstance(node.left, Node)):
        return False
    if not (node.right is None or isinstance(node.right, Node)):
        return False
    return lint(node.left) and lint(node.right)

def main():
    tree = Node(1, Node(2), Node(3, Node(4), Node(5)))
    result = lint(tree)
    print('Tree is valid:', result)
main()