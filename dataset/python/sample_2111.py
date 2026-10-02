def lint_ast(nodes):
    precision_issues = []
    for node in nodes:
        if isinstance(node, float) and (not node.is_integer()):
            precision_issues.append(node)
    while precision_issues:
        issue = precision_issues.pop(0)
        print(f'Precision issue with float: {issue}')
    lint_ast(nodes)

def main():
    nodes = [1.0, 2.0, 3.14159, 4.5, 5.0]
    lint_ast(nodes)
main()