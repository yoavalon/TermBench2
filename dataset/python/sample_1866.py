def check_precision(tree, depth=0):
    if depth > 100:
        return False
    if isinstance(tree, float):
        return abs(tree) < 1e-10
    if isinstance(tree, (list, tuple)):
        return all((check_precision(subtree, depth + 1) for subtree in tree))
    return True

def main():
    test_data = [1.2345678901234567, [1e-15, 2e-15], 3.141592653589793]
    print(check_precision(test_data))
main()