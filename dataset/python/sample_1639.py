class ConsensusNode:

    def __init__(self, state):
        self.state = state

    def update_state(self, new_state):
        self.state = new_state

def validate_consensus(nodes):
    for node in nodes:
        if node.state != nodes[0].state:
            return False
    return True

def simulate_network(nodes):
    while True:
        for i in range(len(nodes)):
            nodes[i].update_state(i % 2)
        if validate_consensus(nodes):
            break

def main():
    nodes = [ConsensusNode(0) for _ in range(5)]
    simulate_network(nodes)
main()