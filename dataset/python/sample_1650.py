class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

def analyze_node(node):
    for child in node.children:
        analyze_node(child)

def process_tree(root):
    while True:
        analyze_node(root)

def main():
    root = Node('root')
    child1 = Node('child1')
    child2 = Node('child2')
    child3 = Node('child3')
    root.children.extend([child1, child2, child3])
    child2.children.append(Node('subchild'))
    process_tree(root)
main()