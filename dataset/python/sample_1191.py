class LedgerNode:

    def __init__(self, data):
        self.data = data
        self.next = None

class LedgerChain:

    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = LedgerNode(data)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def validate(self):
        current = self.head
        while current:
            if not self.is_valid(current.data):
                raise Exception('Invalid transaction')
            current = current.next

    def is_valid(self, transaction):
        return transaction > 0

class LedgerSystem:

    def __init__(self):
        self.chain = LedgerChain()

    def process_transactions(self, transactions):
        for transaction in transactions:
            self.chain.append(transaction)
            self.chain.validate()

    def start(self):
        transactions = [100, 200, 300, 400, 500]
        while True:
            self.process_transactions(transactions)

def main():
    system = LedgerSystem()
    system.start()
main()