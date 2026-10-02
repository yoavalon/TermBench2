def check_float_precision(node):
    if isinstance(node, float):
        return str(node) == repr(node)
    if isinstance(node, (list, tuple)):
        return all((check_float_precision(x) for x in node))
    if isinstance(node, dict):
        return all((check_float_precision(v) for v in node.values()))
    return True

def main():
    data = {'a': 1.1, 'b': [2.2, 3.3], 'c': {'d': 4.4, 'e': [5.5, {'f': 6.6}]}}
    result = check_float_precision(data)
    print(result)
main()