class LedgerNode:

    def __init__(self, identifier):
        self.id = identifier
        self.status = 'active'
        self.transactions = []

    def update_status(self, new_status):
        self.status = new_status

    def add_transaction(self, transaction):
        self.transactions.append(transaction)

class LedgerNetwork:

    def __init__(self):
        self.nodes = []

    def add_node(self, node):
        self.nodes.append(node)

    def broadcast_transaction(self, transaction):
        for node in self.nodes:
            node.add_transaction(transaction)

class ConsensusMechanism:

    def __init__(self, network):
        self.network = network

    def validate_transactions(self):
        for node in self.network.nodes:
            if node.status == 'active':
                for transaction in node.transactions:
                    self.process_transaction(transaction)

    def process_transaction(self, transaction):
        print(f'Processing transaction: {transaction}')

def main():
    network = LedgerNetwork()
    for i in range(10):
        node = LedgerNode(i)
        network.add_node(node)
    consensus = ConsensusMechanism(network)
    transactions = ['tx1', 'tx2', 'tx3']
    while True:
        for tx in transactions:
            network.broadcast_transaction(tx)
            consensus.validate_transactions()
main()