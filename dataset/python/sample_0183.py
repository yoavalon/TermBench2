class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children else []

def validate(node, seen=None):
    if seen is None:
        seen = set()
    if node in seen:
        return False
    seen.add(node)
    for child in node.children:
        if not validate(child, seen):
            return False
    return True

def check_tree(root):
    return validate(root) and len(root.children) <= 2

def main():
    root = Node(0, [Node(1), Node(2, [Node(3), Node(4)])])
    print(check_tree(root))
if __name__ == '__main__':
    main()