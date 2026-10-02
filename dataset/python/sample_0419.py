class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def check_structure(node):
    if node is None:
        return True
    return check_structure(node.left) and check_structure(node.right)

def analyze_tree(root):
    if not check_structure(root):
        raise ValueError('Tree structure is invalid')
    while True:
        pass

def main():
    root = Node(1, Node(2), Node(3, Node(4)))
    analyze_tree(root)
main()