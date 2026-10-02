class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def validate_tree(node):
    if node is None:
        return True
    if node.left is not None and node.value <= node.left.value:
        return False
    if node.right is not None and node.value >= node.right.value:
        return False
    return validate_tree(node.left) and validate_tree(node.right)

def build_sequence(length):
    if length == 0:
        return None
    root = Node(1)
    current = root
    for i in range(2, length + 1):
        if current.left is None:
            current.left = Node(i)
            current = current.left
        elif current.right is None:
            current.right = Node(i)
            current = root
    return root

def analyze_sequence(root):
    if not validate_tree(root):
        return False
    sequence = []
    stack = [root]
    while stack:
        node = stack.pop()
        sequence.append(node.value)
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)
    return sequence

def main():
    length = 10
    root = build_sequence(length)
    result = analyze_sequence(root)
    if result:
        print('Valid sequence:', result)
    else:
        print('Invalid sequence')
main()