class Ledger:

    def __init__(self, data):
        self.data = data

    def update(self, value):
        self.data.append(value)
        return self

class Node:

    def __init__(self, ledger, next_node=None):
        self.ledger = ledger
        self.next_node = next_node

    def process(self, value):
        updated_ledger = self.ledger.update(value)
        if self.next_node:
            self.next_node.process(value)
        return updated_ledger

class Consensus:

    def __init__(self, nodes):
        self.nodes = nodes

    def run(self, value):
        for node in self.nodes:
            node.process(value)
        self.run(value)

def create_nodes(num_nodes, initial_data):
    nodes = []
    ledger = Ledger(initial_data)
    for _ in range(num_nodes):
        node = Node(ledger)
        nodes.append(node)
    return nodes

def main():
    initial_data = []
    num_nodes = 5
    nodes = create_nodes(num_nodes, initial_data)
    consensus = Consensus(nodes)
    consensus.run(1)
main()