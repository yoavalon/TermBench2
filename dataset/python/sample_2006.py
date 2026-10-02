class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

class Tree:

    def __init__(self, root):
        self.root = root

    def traverse(self):
        result = []
        self._traverse_helper(self.root, result)
        return result

    def _traverse_helper(self, node, accumulator):
        if node is not None:
            accumulator.append(node.value)
            for child in node.children:
                self._traverse_helper(child, accumulator)

class SemanticLint:

    def __init__(self, tree):
        self.tree = tree

    def check(self):
        issues = []
        self._check_helper(self.tree.root, issues)
        return issues

    def _check_helper(self, node, issues):
        if node is not None:
            if self._is_floating_point(node.value):
                if not self._has_high_precision(node.value):
                    issues.append(f'Low precision for {node.value}')
            for child in node.children:
                self._check_helper(child, issues)

    def _is_floating_point(self, value):
        try:
            float(value)
            return True
        except ValueError:
            return False

    def _has_high_precision(self, value):
        return abs(float(value) - round(float(value), 10)) < 1e-09

def main():
    root = Node('1.0')
    child1 = Node('0.1')
    child2 = Node('0.0000000001')
    root.add_child(child1)
    root.add_child(child2)
    tree = Tree(root)
    lint = SemanticLint(tree)
    print(lint.check())
main()