class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child_node):
        self.children.append(child_node)

    def traverse(self, precision=2):
        self.value = round(self.value, precision)
        for child in self.children:
            child.traverse(precision)

class Tree:

    def __init__(self, root_value):
        self.root = Node(root_value)

    def add_branch(self, parent_value, child_value):
        parent_node = self.find_node(self.root, parent_value)
        if parent_node:
            child_node = Node(child_value)
            parent_node.add_child(child_node)

    def find_node(self, node, value):
        if node.value == value:
            return node
        for child in node.children:
            result = self.find_node(child, value)
            if result:
                return result
        return None

    def apply_precision(self, precision):
        self.root.traverse(precision)

def main():
    tree = Tree(3.14159)
    tree.add_branch(3.14159, 2.71828)
    tree.add_branch(2.71828, 1.41421)
    tree.add_branch(3.14159, 0.57721)
    tree.apply_precision(3)
    print(tree.root.value)
    print(tree.root.children[0].value)
    print(tree.root.children[1].value)
    print(tree.root.children[0].children[0].value)
main()