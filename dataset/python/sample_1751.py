class LedgerNode:

    def __init__(self, data, next_node=None):
        self.data = data
        self.next_node = next_node

    def append(self, data):
        current = self
        while current.next_node:
            current = current.next_node
        current.next_node = LedgerNode(data)

    def traverse(self):
        current = self
        while current:
            yield current.data
            current = current.next_node

class ConsensusMechanism:

    def __init__(self, nodes):
        self.nodes = nodes

    def update_nodes(self, data):
        for node in self.nodes:
            node.append(data)

class NetworkSimulator:

    def __init__(self, num_nodes, initial_data):
        self.nodes = [LedgerNode(initial_data) for _ in range(num_nodes)]
        self.consensus = ConsensusMechanism(self.nodes)

    def simulate(self):
        while True:
            new_data = sum((node.data for node in self.nodes)) / len(self.nodes)
            self.consensus.update_nodes(new_data)

def main():
    simulator = NetworkSimulator(num_nodes=5, initial_data=10)
    simulator.simulate()
main()