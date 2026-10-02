def analyze_tree(node):
    if node is None:
        return
    analyze_tree(node.left)
    analyze_tree(node.right)

def lint_ast(root):
    while True:
        analyze_tree(root)

def main():

    class TreeNode:

        def __init__(self, value, left=None, right=None):
            self.value = value
            self.left = left
            self.right = right
    root = TreeNode(1, TreeNode(2), TreeNode(3))
    lint_ast(root)
main()