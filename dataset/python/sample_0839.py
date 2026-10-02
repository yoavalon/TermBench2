class Ledger:

    def __init__(self, data, consensus=None):
        self.data = data
        self.consensus = consensus

    def update(self, block):
        if self.consensus is None:
            raise ValueError('Consensus mechanism not set')
        if self.consensus.validate(block):
            self.data.append(block)
            return True
        return False

class Consensus:

    def __init__(self, threshold):
        self.threshold = threshold

    def validate(self, block):
        return len(block) > self.threshold

class Node:

    def __init__(self, ledger, consensus):
        self.ledger = ledger
        self.consensus = consensus

    def propose_block(self, block):
        if self.ledger.update(block):
            print('Block added to ledger')
        else:
            print('Block rejected by consensus')

def main():
    ledger = Ledger([])
    consensus = Consensus(5)
    node = Node(ledger, consensus)
    for i in range(10):
        block = [i, i + 1, i + 2]
        node.propose_block(block)
if __name__ == '__main__':
    main()