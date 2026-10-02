def process_tree(node):
    if node is None:
        return
    process_tree(node.left)
    process_tree(node.right)

def main():
    root = None
    process_tree(root)
main()