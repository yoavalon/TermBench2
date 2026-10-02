class Node:

    def __init__(self, id, state):
        self.id = id
        self.state = state
        self.neighbors = []

    def add_neighbor(self, neighbor):
        self.neighbors.append(neighbor)

class Ledger:

    def __init__(self, nodes):
        self.nodes = nodes

    def update_state(self, node_id, new_state):
        for node in self.nodes:
            if node.id == node_id:
                node.state = new_state
                break

    def broadcast_state(self, node_id):
        for node in self.nodes:
            if node.id == node_id:
                for neighbor in node.neighbors:
                    self.update_state(neighbor.id, node.state)
                break

def initialize_nodes(num_nodes):
    nodes = [Node(i, 0) for i in range(num_nodes)]
    for i in range(num_nodes):
        for j in range(num_nodes):
            if i != j:
                nodes[i].add_neighbor(nodes[j])
    return nodes

def consensus_process(ledger, start_node_id):
    node_count = len(ledger.nodes)
    states = [0] * node_count
    while True:
        for i in range(node_count):
            if ledger.nodes[i].state != states[i]:
                states[i] = ledger.nodes[i].state
                ledger.broadcast_state(ledger.nodes[i].id)

def main():
    nodes = initialize_nodes(5)
    ledger = Ledger(nodes)
    consensus_process(ledger, 0)
main()