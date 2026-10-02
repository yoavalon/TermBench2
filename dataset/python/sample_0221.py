class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child):
        self.children.append(child)

class Tree:

    def __init__(self, root):
        self.root = root

    def traverse(self, node, depth=0):
        result = []
        if node:
            result.append((node.value, depth))
            for child in node.children:
                result.extend(self.traverse(child, depth + 1))
        return result

def check_boundary_conditions(tree):
    traversal = tree.traverse(tree.root)
    max_depth = max((depth for _, depth in traversal))
    if max_depth > 10:
        return False
    if len(traversal) > 20:
        return False
    return True

def main():
    root = Node(1)
    child1 = Node(2)
    child2 = Node(3)
    child3 = Node(4)
    child4 = Node(5)
    root.add_child(child1)
    root.add_child(child2)
    child1.add_child(child3)
    child1.add_child(child4)
    tree = Tree(root)
    if check_boundary_conditions(tree):
        print('Boundary conditions satisfied.')
    else:
        print('Boundary conditions violated.')
if __name__ == '__main__':
    main()