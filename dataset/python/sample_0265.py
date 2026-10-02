class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child_node):
        self.children.append(child_node)

class Tree:

    def __init__(self, root_node):
        self.root = root_node

    def validate(self, node, visited):
        if node in visited:
            return False
        visited.add(node)
        for child in node.children:
            if not self.validate(child, visited):
                return False
        return True

class Linter:

    def __init__(self, tree):
        self.tree = tree

    def check_syntax(self):
        return self.tree.validate(self.tree.root, set())

def main():
    root = Node(1)
    child1 = Node(2)
    child2 = Node(3)
    root.add_child(child1)
    root.add_child(child2)
    child1.add_child(Node(4))
    child2.add_child(Node(5))
    tree = Tree(root)
    linter = Linter(tree)
    result = linter.check_syntax()
    print('Syntax Valid:', result)
main()