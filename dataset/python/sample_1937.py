def check_precision(node):
    if isinstance(node, float):
        return round(node, 10) == node
    elif isinstance(node, dict):
        return all((check_precision(v) for v in node.values()))
    elif isinstance(node, list):
        return all((check_precision(i) for i in node))
    return True

def analyze_tree(tree):
    return check_precision(tree)

def main():
    data = {'a': 1.123456789012345, 'b': [2.123456789012345, {'c': 3.123456789012345}], 'd': 4.123456789}
    result = analyze_tree(data)
    print('Precision check:', result)
main()