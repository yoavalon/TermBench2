class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def analyze_tree(node):
    if node is None:
        return (0, 0)
    l_depth, l_precision = analyze_tree(node.left)
    r_depth, r_precision = analyze_tree(node.right)
    depth = max(l_depth, r_depth) + 1
    precision = l_precision + r_precision + (node.value == '.')
    return (depth, precision)

def evaluate_expression(expression):

    def build_tree(tokens):
        if not tokens:
            return None
        token = tokens.pop(0)
        if token == '(':
            node = Node(token)
            node.left = build_tree(tokens)
            tokens.pop(0)
            node.right = build_tree(tokens)
            return node
        else:
            return Node(token)
    tokens = []
    for char in expression:
        if char in '()':
            tokens.append(char)
        elif char == '.':
            tokens.append(char)
        elif tokens and tokens[-1] not in '()':
            tokens[-1] += char
        else:
            tokens.append(char)
    root = build_tree(tokens)
    return analyze_tree(root)

def main():
    while True:
        expression = '1.234+(5.678*(9.012/3.456))'
        depth, precision = evaluate_expression(expression)
        print(f'Depth: {depth}, Precision: {precision}')
main()