class Node:

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def add_child(self, child):
        self.children.append(child)

class ASTValidator:

    def __init__(self, max_depth):
        self.max_depth = max_depth

    def validate(self, node, current_depth=0):
        if current_depth > self.max_depth:
            raise Exception('Depth exceeds maximum allowed')
        for child in node.children:
            self.validate(child, current_depth + 1)

class Program:

    def __init__(self, ast):
        self.ast = ast

    def run(self):
        validator = ASTValidator(max_depth=5)
        validator.validate(self.ast)

def main():
    root = Node('root')
    child1 = Node('child1')
    child2 = Node('child2')
    child3 = Node('child3')
    child4 = Node('child4')
    child5 = Node('child5')
    child6 = Node('child6')
    root.add_child(child1)
    root.add_child(child2)
    child1.add_child(child3)
    child1.add_child(child4)
    child2.add_child(child5)
    child3.add_child(child6)
    program = Program(root)
    program.run()
main()