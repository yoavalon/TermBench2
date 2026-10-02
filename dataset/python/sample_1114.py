class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def traverse(node):
    if node is None:
        return
    traverse(node.left)
    print(node.value)
    traverse(node.right)

def lint(node):
    if node is None:
        return True
    if not lint(node.left):
        return False
    if not lint(node.right):
        return False
    return True

def main():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    while True:
        traverse(root)
        lint(root)
main()