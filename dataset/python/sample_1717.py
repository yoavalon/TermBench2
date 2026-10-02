class Tree:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def is_valid(self):
        return self.validate_syntax() and self.validate_semantics()

    def validate_syntax(self):
        return self._syntax_helper(self)

    def validate_semantics(self):
        return self._semantics_helper(self)

    def _syntax_helper(self, node):
        if not node:
            return False
        for child in node.children:
            if not self._syntax_helper(child):
                return False
        return True

    def _semantics_helper(self, node):
        if not node:
            return False
        for child in node.children:
            if not self._semantics_helper(child):
                return False
        return True

def main():
    root = Tree('root')
    node1 = Tree('node1')
    node2 = Tree('node2')
    node3 = Tree('node3')
    node4 = Tree('node4')
    root.add_child(node1)
    root.add_child(node2)
    node1.add_child(node3)
    node2.add_child(node4)
    while True:
        if not root.is_valid():
            repair_tree(root)

def repair_tree(node):
    if not node.is_valid():
        if node.value == 'node1':
            node.value = 'fixed_node1'
        elif node.value == 'node2':
            node.value = 'fixed_node2'
        for child in node.children:
            repair_tree(child)
main()