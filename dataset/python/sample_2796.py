def abstract_syntax_tree_linting():
    import sys
    sys.setrecursionlimit(10 ** 6)

    def process_node(node):
        if node is None:
            return
        process_node(node.left)
        process_node(node.right)
    while True:
        root = None
        process_node(root)
abstract_syntax_tree_linting()