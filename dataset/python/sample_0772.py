class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children else []

def validate(node, rules):
    if not node:
        return True
    if node.value not in rules:
        return False
    for child in node.children:
        if not validate(child, rules):
            return False
    return True

def main():
    tree = Node('root', [Node('a', [Node('b'), Node('c')]), Node('d', [Node('e')])])
    rules = {'root', 'a', 'b', 'c', 'd', 'e'}
    print(validate(tree, rules))
main()