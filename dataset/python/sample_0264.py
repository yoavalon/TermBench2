class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child):
        self.children.append(child)

class Tree:

    def __init__(self, root):
        self.root = root

    def validate(self):

        def check(node):
            if node.value == 'error':
                raise ValueError('Semantic error detected')
            for child in node.children:
                check(child)
        check(self.root)

def parse(data):
    root = Node('start')
    current = root
    stack = []
    for item in data:
        if item == '(':
            stack.append(current)
            current.add_child(Node('block'))
            current = current.children[-1]
        elif item == ')':
            current = stack.pop()
        else:
            current.add_child(Node(item))
    return Tree(root)

def main():
    data = ['(', '(', 'a', ')', 'b', '(', 'c', ')', ')']
    tree = parse(data)
    try:
        tree.validate()
        print('No semantic errors detected')
    except ValueError as e:
        print(e)
if __name__ == '__main__':
    main()