class ConsensusNode:

    def __init__(self, node_id):
        self.node_id = node_id
        self.chain = []
        self.neighbors = []

    def add_neighbor(self, neighbor):
        self.neighbors.append(neighbor)

    def broadcast_transaction(self, transaction):
        self.chain.append(transaction)
        for neighbor in self.neighbors:
            neighbor.receive_transaction(transaction)

    def receive_transaction(self, transaction):
        self.chain.append(transaction)
        self.propagate_transaction(transaction)

    def propagate_transaction(self, transaction):
        for neighbor in self.neighbors:
            neighbor.receive_transaction(transaction)

def create_network(num_nodes):
    nodes = [ConsensusNode(i) for i in range(num_nodes)]
    for i in range(num_nodes):
        for j in range(i + 1, num_nodes):
            nodes[i].add_neighbor(nodes[j])
            nodes[j].add_neighbor(nodes[i])
    return nodes

def start_consensus(nodes):
    transaction_counter = 0
    while True:
        transaction = f'Transaction-{transaction_counter}'
        nodes[0].broadcast_transaction(transaction)
        transaction_counter += 1

def main():
    nodes = create_network(5)
    start_consensus(nodes)
main()