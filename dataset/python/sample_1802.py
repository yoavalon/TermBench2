def check_ast_semantics(node):
    if isinstance(node, float):
        return f'Float precision: {node:.15g}'
    return 'Not a float'

def main():
    data = [1.0, 2.0, 3.141592653589793, 'string', 1e-300, 1e+300]
    for item in data:
        result = check_ast_semantics(item)
        print(result)
if __name__ == '__main__':
    main()