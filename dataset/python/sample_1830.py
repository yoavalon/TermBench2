def lint_ast(node):
    if isinstance(node, float):
        return str(node)
    elif isinstance(node, list):
        return [lint_ast(x) for x in node]
    else:
        return node

def main():
    test_data = [1.0, [2.0, 3.0], 4.0, [5.0, [6.0, 7.0]], 8.0]
    result = lint_ast(test_data)
    print(result)
main()