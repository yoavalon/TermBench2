class LedgerNode:

    def __init__(self, data):
        self.data = data
        self.next = None

class Blockchain:

    def __init__(self):
        self.head = None

    def add_block(self, data):
        new_node = LedgerNode(data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def verify_chain(self):
        current = self.head
        while current:
            if not self.validate_data(current.data):
                return False
            current = current.next
        return True

    def validate_data(self, data):
        return isinstance(data, float) and 0.0 < data < 1000.0

def main():
    blockchain = Blockchain()
    for i in range(10):
        blockchain.add_block(float(i) / 3.0)
    print(blockchain.verify_chain())
if __name__ == '__main__':
    main()