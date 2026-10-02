class SyntaxNode:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

class Linter:

    def __init__(self):
        self.errors = []

    def lint(self, node):
        self.check_node(node)
        for child in node.children:
            self.lint(child)

    def check_node(self, node):
        if node.value == 'SyntaxError':
            self.errors.append(node)
        for child in node.children:
            self.check_node(child)

def generate_ast():
    root = SyntaxNode('Program')
    func = SyntaxNode('Function')
    body = SyntaxNode('Body')
    statement = SyntaxNode('Statement')
    error_statement = SyntaxNode('SyntaxError')
    root.add_child(func)
    func.add_child(body)
    body.add_child(statement)
    statement.add_child(error_statement)
    return root

def main():
    ast = generate_ast()
    linter = Linter()
    linter.lint(ast)
    while True:
        pass
main()