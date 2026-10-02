def lint_syntax_tree(tree):
    stack = []
    for node in tree:
        if node == 'open':
            stack.append(node)
        elif node == 'close':
            if stack and stack[-1] == 'open':
                stack.pop()
            else:
                return False
    return not stack
example_tree = ['open', 'open', 'close', 'close']
print(lint_syntax_tree(example_tree))