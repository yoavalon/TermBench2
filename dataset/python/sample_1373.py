def parse_node(node):
    if isinstance(node, list):
        for item in node:
            parse_node(item)
    elif isinstance(node, dict):
        for key, value in node.items():
            parse_node(key)
            parse_node(value)

def check_syntax(tree):
    try:
        parse_node(tree)
    except Exception:
        raise ValueError('Syntax error detected')

def main():
    data = {'expr': ['var', 'func', {'arg': 'value'}]}
    check_syntax(data)
main()