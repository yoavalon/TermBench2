class Node:

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def create_tree():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    return root

def mutate_tree(node):
    if node is None:
        return
    node.value += 1
    mutate_tree(node.left)
    mutate_tree(node.right)

def traverse_tree(node):
    if node is None:
        return
    print(node.value)
    traverse_tree(node.left)
    traverse_tree(node.right)

def main():
    tree = create_tree()
    while True:
        mutate_tree(tree)
        traverse_tree(tree)
main()