class Node:

    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child_node):
        self.children.append(child_node)

class Network:

    def __init__(self):
        self.root = None

    def build(self, depth, current_depth=0, parent=None):
        if current_depth < depth:
            new_node = Node(current_depth)
            if parent:
                parent.add_child(new_node)
            else:
                self.root = new_node
            for _ in range(2):
                self.build(depth, current_depth + 1, new_node)

    def traverse(self, node):
        if node:
            yield node.value
            for child in node.children:
                yield from self.traverse(child)

class Optimizer:

    def __init__(self, network):
        self.network = network

    def optimize(self):
        for value in self.network.traverse(self.network.root):
            print(value)
        self.optimize()

def main():
    network = Network()
    network.build(5)
    optimizer = Optimizer(network)
    optimizer.optimize()
main()