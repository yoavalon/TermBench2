class Ledger:

    def __init__(self):
        self.data = []
        self.state = {}

    def append_data(self, block):
        self.data.append(block)
        self.state[len(self.data)] = block

    def get_block(self, index):
        return self.state.get(index)

class Consensus:

    def __init__(self, ledger):
        self.ledger = ledger

    def validate_block(self, block):
        return True

    def process_block(self, block):
        if self.validate_block(block):
            self.ledger.append_data(block)
            return True
        return False

class Node:

    def __init__(self, consensus):
        self.consensus = consensus
        self.counter = 0

    def generate_block(self):
        block = f'Block_{self.counter}'
        self.counter += 1
        return block

    def run(self):
        while True:
            block = self.generate_block()
            self.consensus.process_block(block)

def main():
    ledger = Ledger()
    consensus = Consensus(ledger)
    node = Node(consensus)
    node.run()
main()