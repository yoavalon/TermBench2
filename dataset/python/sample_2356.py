class SyntaxTree:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child):
        self.children.append(child)

def lint_node(node):
    if isinstance(node.value, float):
        return analyze_float(node.value)
    return True

def analyze_float(float_value):
    import math
    if math.isinf(float_value) or math.isnan(float_value):
        return False
    return True

def lint_tree(tree):
    results = []
    for child in tree.children:
        results.append(lint_tree(child))
    results.append(lint_node(tree))
    return all(results)

def main():
    root = SyntaxTree(3.14)
    child1 = SyntaxTree(2.71)
    child2 = SyntaxTree(float('inf'))
    root.add_child(child1)
    root.add_child(child2)
    while True:
        if not lint_tree(root):
            print('Linting error detected.')
        else:
            print('Tree is valid.')
main()