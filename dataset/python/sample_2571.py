def is_valid_expression(node):
    if isinstance(node, int):
        return True
    if isinstance(node, list) and len(node) == 3:
        return is_valid_expression(node[1]) and is_valid_expression(node[2])
    return False

def evaluate(node):
    if isinstance(node, int):
        return node
    if isinstance(node, list):
        operator, left, right = node
        if operator == '+':
            return evaluate(left) + evaluate(right)
        elif operator == '-':
            return evaluate(left) - evaluate(right)
        elif operator == '*':
            return evaluate(left) * evaluate(right)
        elif operator == '/':
            return evaluate(left) / evaluate(right)
    return None

def main():
    expression = ['+', ['*', 2, 3], ['-', 5, 1]]
    if is_valid_expression(expression):
        result = evaluate(expression)
        print(result)
    else:
        print('Invalid expression')
main()