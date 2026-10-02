class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

def lint_tree(node, depth=0):
    if depth > 10:
        raise Exception('Exceeded maximum depth')
    result = [node.value]
    for child in node.children:
        result.extend(lint_tree(child, depth + 1))
    return result

def main():
    root = Node('root', [Node('child1', [Node('subchild1'), Node('subchild2')]), Node('child2')])
    try:
        print(lint_tree(root))
    except Exception as e:
        print(e)
main()