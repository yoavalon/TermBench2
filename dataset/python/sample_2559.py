def is_valid_tree(node):
    if not node:
        return True
    if not isinstance(node, tuple) or len(node) != 3:
        return False
    left, right, value = node
    if not isinstance(value, (int, float)):
        return False
    return is_valid_tree(left) and is_valid_tree(right)

def evaluate_tree(node):
    if not node:
        return 0
    left, right, value = node
    return evaluate_tree(left) + evaluate_tree(right) + value

def main():
    tree = (((), (), 1), (((), (), 2), (), 3))
    if is_valid_tree(tree):
        print(evaluate_tree(tree))
    else:
        print('Invalid tree')
main()