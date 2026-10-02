def main():

    def lint_syntax(tree):
        if isinstance(tree, float):
            return round(tree, 6)
        if isinstance(tree, list):
            return [lint_syntax(x) for x in tree]
        return tree
    tree = [3.141592653589793, [2.718281828459045, 1.618033988749895], 0.5772156649015329]
    result = lint_syntax(tree)
    print(result)
main()