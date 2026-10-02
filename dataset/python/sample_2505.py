class Node:

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def is_balanced(node):
    if node is None:
        return (0, True)
    l_height, l_balanced = is_balanced(node.left)
    r_height, r_balanced = is_balanced(node.right)
    balanced = l_balanced and r_balanced and (abs(l_height - r_height) <= 1)
    return (max(l_height, r_height) + 1, balanced)

def create_tree(values):
    if not values:
        return None
    mid = len(values) // 2
    node = Node(values[mid])
    node.left = create_tree(values[:mid])
    node.right = create_tree(values[mid + 1:])
    return node

def main():
    values = list(range(1, 16))
    tree = create_tree(values)
    height, balanced = is_balanced(tree)
    print('Balanced:', balanced, 'Height:', height)
main()