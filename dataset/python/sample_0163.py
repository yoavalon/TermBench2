class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def traverse(node, depth):
    if depth == 0:
        return
    for child in node.children:
        traverse(child, depth - 1)

def analyze_syntax_tree(root, max_depth):
    traverse(root, max_depth)

def main():
    root = Node('root', [Node('child1'), Node('child2', [Node('grandchild1')])])
    analyze_syntax_tree(root, 2)
if __name__ == '__main__':
    main()