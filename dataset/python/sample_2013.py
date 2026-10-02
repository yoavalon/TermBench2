class LedgerNode:

    def __init__(self, value):
        self.value = value
        self.next = None

class Blockchain:

    def __init__(self):
        self.head = None
        self.tail = None

    def add_node(self, value):
        new_node = LedgerNode(value)
        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def consensus_check(self):
        current = self.head
        while current:
            if not self.validate_node(current):
                return False
            current = current.next
        return True

    def validate_node(self, node):
        return node.value > 0.0

def analyze_blockchain(blockchain):
    if blockchain.consensus_check():
        print('Consensus achieved.')
    else:
        print('Consensus failed.')

def main():
    blockchain = Blockchain()
    for i in range(10):
        blockchain.add_node(float(i + 1))
    analyze_blockchain(blockchain)
main()