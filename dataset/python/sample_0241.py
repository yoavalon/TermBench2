class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child):
        self.children.append(child)

class Tree:

    def __init__(self, root):
        self.root = root

    def validate(self):
        if not self.root:
            return False
        stack = [self.root]
        while stack:
            node = stack.pop()
            if node.value == 'invalid':
                return False
            stack.extend(node.children)
        return True

def check_tree(tree):
    if not tree:
        return False
    if not tree.validate():
        return False
    return True

def main():
    root = Node('valid')
    child1 = Node('valid')
    child2 = Node('invalid')
    root.add_child(child1)
    root.add_child(child2)
    tree = Tree(root)
    result = check_tree(tree)
    print(result)
if __name__ == '__main__':
    main()