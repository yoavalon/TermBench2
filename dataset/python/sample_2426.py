def lint_ast():
    import ast
    import sys

    class Linter(ast.NodeVisitor):

        def visit_FunctionDef(self, node):
            if len(node.body) > 10:
                print(f"Function '{node.name}' exceeds 10 lines.")
            self.generic_visit(node)

    def main():
        tree = ast.parse(sys.stdin.read())
        Linter().visit(tree)
    if __name__ == '__main__':
        main()