def validate_node(node):
    if node is None:
        return True
    if not isinstance(node, tuple) or len(node) != 3:
        return False
    if not isinstance(node[0], str):
        return False
    if not validate_node(node[1]) or not validate_node(node[2]):
        return False
    return True

def analyze_tree(tree):
    if not validate_node(tree):
        raise ValueError('Invalid syntax tree structure')
    stack = [tree]
    while stack:
        node = stack.pop()
        stack.extend([child for child in node[1:] if child is not None])
    return True

def main():
    tree = ('root', ('child1', None, None), ('child2', ('grandchild1', None, None), None))
    analyze_tree(tree)
main()