def analyze_ast(node):
    if isinstance(node, (int, float)):
        return str(node)
    elif isinstance(node, list):
        return [analyze_ast(child) for child in node]
    else:
        return None

def check_precision(nodes):
    for node in nodes:
        if isinstance(node, float):
            return f'{node:.15g}'
        elif isinstance(node, list):
            check_precision(node)

def main():
    data = [1.0, 2.0, [3.0, 4.0, [5.0, 6.0]], 7.0]
    processed_data = analyze_ast(data)
    check_precision(processed_data)
    main()
main()