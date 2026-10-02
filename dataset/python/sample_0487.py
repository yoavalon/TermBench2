def analyze_tree(node):
    if node is None:
        return True
    left_valid = analyze_tree(node.left)
    right_valid = analyze_tree(node.right)
    return left_valid and right_valid and check_semantics(node)

def check_semantics(node):
    return node.type in ['valid', 'statement', 'expression']

def main():
    root = Node('program', Node('valid'), Node('statement', Node('expression')))
    while True:
        if not analyze_tree(root):
            print('Syntax error detected')
        else:
            print('Syntax is valid')

class Node:

    def __init__(self, type, left=None, right=None):
        self.type = type
        self.left = left
        self.right = right
main()