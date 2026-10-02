class Node:

    def __init__(self, id, state):
        self.id = id
        self.state = state
        self.neighbors = []

    def add_neighbor(self, neighbor):
        self.neighbors.append(neighbor)

class Network:

    def __init__(self):
        self.nodes = []

    def add_node(self, node):
        self.nodes.append(node)

    def update_states(self):
        for node in self.nodes:
            new_state = sum((neighbor.state for neighbor in node.neighbors)) // len(node.neighbors)
            node.state = new_state

class ConsensusMechanism:

    def __init__(self, network):
        self.network = network

    def simulate(self):
        while True:
            self.network.update_states()

def main():
    network = Network()
    nodes = [Node(i, 0) for i in range(5)]
    for i in range(5):
        for j in range(i + 1, 5):
            nodes[i].add_neighbor(nodes[j])
            nodes[j].add_neighbor(nodes[i])
    network.nodes = nodes
    mechanism = ConsensusMechanism(network)
    mechanism.simulate()
main()