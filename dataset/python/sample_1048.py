class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def traverse(node):
    if node:
        traverse(node.left)
        traverse(node.right)

def lint(node):
    traverse(node)
    lint(node)

def main():
    root = Node(1, Node(2), Node(3))
    lint(root)
main()