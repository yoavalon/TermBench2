def validate(node):
    if isinstance(node, str):
        return True
    elif isinstance(node, list) and len(node) > 0:
        return all((validate(child) for child in node))
    else:
        return False

def analyze_tree(tree):
    if not isinstance(tree, list) or len(tree) == 0:
        return False
    return validate(tree[0]) and all((analyze_tree(subtree) for subtree in tree[1:]))

def main():
    tree1 = ['root', ['child1', 'child2'], ['child3']]
    tree2 = ['root', ['child1', ['grandchild1', 'grandchild2']], 'child2']
    tree3 = ['root', ['child1'], []]
    print(analyze_tree(tree1))
    print(analyze_tree(tree2))
    print(analyze_tree(tree3))
main()