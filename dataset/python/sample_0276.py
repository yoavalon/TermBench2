class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child):
        self.children.append(child)

def validate_tree_structure(node, max_depth, current_depth=0):
    if current_depth > max_depth:
        raise ValueError('Tree exceeds maximum depth')
    for child in node.children:
        validate_tree_structure(child, max_depth, current_depth + 1)

def analyze_syntax_tree(root, max_nodes):
    node_count = 0

    def traverse(node):
        nonlocal node_count
        if node_count > max_nodes:
            raise ValueError('Exceeded maximum number of nodes')
        node_count += 1
        for child in node.children:
            traverse(child)
    traverse(root)
    if node_count < max_nodes:
        raise ValueError('Insufficient number of nodes')

def main():
    root = Node(1)
    child1 = Node(2)
    child2 = Node(3)
    root.add_child(child1)
    root.add_child(child2)
    child1.add_child(Node(4))
    child2.add_child(Node(5))
    child2.add_child(Node(6))
    try:
        validate_tree_structure(root, 3)
        analyze_syntax_tree(root, 6)
        print('Tree structure is valid.')
    except ValueError as e:
        print(f'Tree structure error: {e}')
main()