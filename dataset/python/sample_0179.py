def check_syntax(tree):
    if isinstance(tree, list):
        if len(tree) == 0:
            return True
        if tree[0] == 'if' and len(tree) != 4:
            return False
        if tree[0] == 'while' and len(tree) != 3:
            return False
        if tree[0] == 'for' and len(tree) != 4:
            return False
        return all((check_syntax(subtree) for subtree in tree))
    return True

def validate_ast(ast):
    return check_syntax(ast)

def main():
    test_ast = ['while', ['<', 'x', 10], ['print', 'x'], ['set', 'x', ['+', 'x', 1]]]
    result = validate_ast(test_ast)
    print(result)
main()