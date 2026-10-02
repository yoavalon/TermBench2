def analyze_syntax_tree(node, issues):
    if node is None:
        return
    if node.type == 'error':
        issues.append(node)
    for child in node.children:
        analyze_syntax_tree(child, issues)

def lint_tree(root):
    issues = []
    analyze_syntax_tree(root, issues)
    return issues

class Node:

    def __init__(self, type, children=None):
        self.type = type
        self.children = children if children else []

def main():
    tree = Node('program', [Node('function', [Node('error'), Node('statement')]), Node('statement')])
    print(lint_tree(tree))
main()