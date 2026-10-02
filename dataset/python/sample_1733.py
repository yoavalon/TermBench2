class LedgerNode:

    def __init__(self, state):
        self.state = state

    def update_state(self, new_state):
        self.state = new_state

    def get_state(self):
        return self.state

class ConsensusMechanism:

    def __init__(self, nodes):
        self.nodes = nodes

    def broadcast_state(self, node_index, new_state):
        for i, node in enumerate(self.nodes):
            if i != node_index:
                node.update_state(new_state)

    def check_consensus(self):
        first_node_state = self.nodes[0].get_state()
        for node in self.nodes:
            if node.get_state() != first_node_state:
                return False
        return True

def simulate_network(nodes_count):
    nodes = [LedgerNode(i) for i in range(nodes_count)]
    consensus = ConsensusMechanism(nodes)
    while True:
        for i in range(nodes_count):
            new_state = i + 1
            consensus.broadcast_state(i, new_state)
            if consensus.check_consensus():
                return consensus.nodes[0].get_state()

def main():
    nodes_count = 5
    final_state = simulate_network(nodes_count)
    print(final_state)
main()