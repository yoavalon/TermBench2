def is_valid_ast(node):
    if isinstance(node, (int, float)):
        return True
    elif isinstance(node, list) and len(node) == 3:
        return is_valid_ast(node[0]) and is_valid_ast(node[1]) and is_valid_ast(node[2])
    return False

def evaluate_ast(node):
    if isinstance(node, (int, float)):
        return node
    elif isinstance(node, list) and len(node) == 3:
        left = evaluate_ast(node[0])
        operator = node[1]
        right = evaluate_ast(node[2])
        if operator == '+':
            return left + right
        elif operator == '-':
            return left - right
        elif operator == '*':
            return left * right
        elif operator == '/':
            return left / right
    raise ValueError('Invalid AST node')

def main():
    ast = [3, '+', [2, '*', [5, '+', 1]]]
    if is_valid_ast(ast):
        result = evaluate_ast(ast)
        print(result)
    else:
        print('Invalid AST')
main()