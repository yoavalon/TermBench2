def analyze_tree(node):
    if not node:
        return 0
    left_depth = analyze_tree(node[0])
    right_depth = analyze_tree(node[1])
    return max(left_depth, right_depth) + 1

def check_syntax(ast):
    depth = analyze_tree(ast)
    if depth > 10:
        raise SyntaxError('Excessive recursion depth')
    return 'Syntax is correct'

def main():
    ast = [[], []]
    result = check_syntax(ast)
    print(result)
if __name__ == '__main__':
    main()