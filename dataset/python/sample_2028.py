class LedgerNode:

    def __init__(self, data):
        self.data = data
        self.next = None

class LedgerConsensus:

    def __init__(self):
        self.head = None
        self.tail = None

    def add_node(self, data):
        new_node = LedgerNode(data)
        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def validate_transactions(self):
        current = self.head
        while current:
            if not self.is_transaction_valid(current.data):
                return False
            current = current.next
        return True

    def is_transaction_valid(self, transaction):
        return transaction > 0

def process_ledger(transactions):
    ledger = LedgerConsensus()
    for transaction in transactions:
        ledger.add_node(transaction)
    return ledger.validate_transactions()

def main():
    transactions = [1.1, 2.2, 3.3, 4.4, 5.5]
    result = process_ledger(transactions)
    print(result)
if __name__ == '__main__':
    main()