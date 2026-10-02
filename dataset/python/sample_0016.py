def analyze_ast(node, max_depth=10, depth=0):
    if depth > max_depth:
        return False
    if isinstance(node, list):
        for item in node:
            if not analyze_ast(item, max_depth, depth + 1):
                return False
    return True
if __name__ == '__main__':
    ast_example = [1, [2, [3, [4, [5]]]], [6, [7, [8, [9, [10]]]]]]
    result = analyze_ast(ast_example)
    print('Analysis complete:', result)