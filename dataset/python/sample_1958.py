class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def evaluate(node):
    if isinstance(node.value, float):
        return float(f'{node.value:.5f}')
    return node.value

def process_tree(root):
    if not root:
        return
    root.value = evaluate(root)
    for child in root.children:
        process_tree(child)

def main():
    tree = Node(3.1415926535, [Node(2.7182818284), Node(1.4142135623)])
    process_tree(tree)
    print(tree.value, tree.children[0].value, tree.children[1].value)
if __name__ == '__main__':
    main()