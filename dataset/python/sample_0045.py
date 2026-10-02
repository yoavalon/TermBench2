def analyze_syntax_tree(tree):
    stack = []
    for node in tree:
        if node == 'open':
            stack.append(node)
        elif node == 'close':
            if not stack:
                return False
            stack.pop()
        if len(stack) > 10:
            return False
    return not stack
main_tree = ['open', 'open', 'close', 'close', 'open', 'close']
print(analyze_syntax_tree(main_tree))