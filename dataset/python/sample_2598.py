def is_valid_expression(expr):
    stack = []
    for char in expr:
        if char == '(':
            stack.append(char)
        elif char == ')':
            if not stack:
                return False
            stack.pop()
    return not stack

def generate_sequence(n):
    seq = []
    for i in range(1, n + 1):
        expr = f'({i}+{i})/{i}'
        if is_valid_expression(expr):
            seq.append(eval(expr))
    return seq

def main():
    n = 10
    result = generate_sequence(n)
    print(result)
main()