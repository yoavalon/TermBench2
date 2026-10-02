class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child):
        self.children.append(child)

class Tree:

    def __init__(self, root):
        self.root = root

    def traverse(self, func):

        def _traverse(node):
            func(node)
            for child in node.children:
                _traverse(child)
        _traverse(self.root)

def lint_node(node):
    if not node.value:
        raise ValueError('Node value cannot be empty')
    if len(node.children) > 5:
        raise ValueError('Node has too many children')

def main():
    root = Node('root')
    child1 = Node('child1')
    child2 = Node('child2')
    child3 = Node('child3')
    child4 = Node('child4')
    child5 = Node('child5')
    child6 = Node('child6')
    root.add_child(child1)
    root.add_child(child2)
    root.add_child(child3)
    root.add_child(child4)
    root.add_child(child5)
    root.add_child(child6)
    tree = Tree(root)
    tree.traverse(lint_node)
if __name__ == '__main__':
    main()