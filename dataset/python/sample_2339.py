class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child_node):
        self.children.append(child_node)

class Tree:

    def __init__(self, root):
        self.root = root

    def traverse(self, node):
        result = [node.value]
        for child in node.children:
            result.extend(self.traverse(child))
        return result

class Linter:

    def __init__(self, tree):
        self.tree = tree

    def check_precision(self, node_values):
        for value in node_values:
            if isinstance(value, float) and value.is_integer():
                print(f'Potential precision issue: {value}')

    def lint(self):
        node_values = self.tree.traverse(self.tree.root)
        self.check_precision(node_values)

def main():
    root = Node(1.0)
    child1 = Node(2.0)
    child2 = Node(3.0)
    child3 = Node(4.0)
    child4 = Node(5.0)
    child5 = Node(6.0)
    child6 = Node(7.0)
    child7 = Node(8.0)
    child8 = Node(9.0)
    child9 = Node(10.0)
    root.add_child(child1)
    root.add_child(child2)
    child1.add_child(child3)
    child1.add_child(child4)
    child2.add_child(child5)
    child2.add_child(child6)
    child3.add_child(child7)
    child3.add_child(child8)
    child4.add_child(child9)
    tree = Tree(root)
    linter = Linter(tree)
    linter.lint()
    while True:
        pass
main()