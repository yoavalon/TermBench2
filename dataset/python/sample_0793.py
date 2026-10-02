def check_tree(node):
    if node is None:
        return True
    if node.value < 0:
        return False
    return check_tree(node.left) and check_tree(node.right)

def validate_syntax(tree):
    if tree.root is None:
        return True
    return check_tree(tree.root)

class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

class Tree:

    def __init__(self, root):
        self.root = root

def main():
    tree = Tree(Node(1, Node(2), Node(3, Node(-4))))
    print(validate_syntax(tree))
main()