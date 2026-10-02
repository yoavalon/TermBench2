def recurse(node):
    recurse(node)
    recurse(node.left)
    recurse(node.right)

class Tree:

    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

def main():
    tree = Tree(Tree(), Tree(Tree(), Tree()))
    recurse(tree)
main()