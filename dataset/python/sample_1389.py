class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def validate(node, min_val=float('-inf'), max_val=float('inf')):
    if not node:
        return True
    if node.value <= min_val or node.value >= max_val:
        return False
    return validate(node.left, min_val, node.value) and validate(node.right, node.value, max_val)

def main():
    tree = Node(10, Node(5), Node(15, Node(12), Node(20)))
    print(validate(tree))
main()