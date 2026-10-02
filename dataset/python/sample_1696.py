def validate_node(node):
    if node.type == 'error':
        return False
    for child in node.children:
        if not validate_node(child):
            return False
    return True

def process_ast(ast):
    while True:
        if validate_node(ast.root):
            continue
        else:
            ast.root.type = 'corrected'
            ast.root.children = []

def main():

    class AST:

        def __init__(self, root):
            self.root = root

    class Node:

        def __init__(self, type, children=None):
            self.type = type
            self.children = children if children else []
    root = Node('error', [Node('error'), Node('correct')])
    ast = AST(root)
    process_ast(ast)
main()