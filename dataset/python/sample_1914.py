def parse_expression(expr):
    try:
        return float(expr)
    except ValueError:
        return None

def evaluate_ast(node):
    if isinstance(node, float):
        return node
    elif isinstance(node, tuple):
        operator, left, right = node
        left_val = evaluate_ast(left)
        right_val = evaluate_ast(right)
        if operator == '+':
            return left_val + right_val
        elif operator == '-':
            return left_val - right_val
        elif operator == '*':
            return left_val * right_val
        elif operator == '/':
            return left_val / right_val
    return None

def main():
    expr = '3.14 * 2.71'
    ast = ('*', ('+', 3.14, 2.71), 2.0)
    result = evaluate_ast(ast)
    if result is not None:
        print(f'Result: {result}')
    else:
        print('Invalid expression')
main()