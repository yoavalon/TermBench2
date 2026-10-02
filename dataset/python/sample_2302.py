class Node:

    def __init__(self, value, precision):
        self.value = value
        self.precision = precision
        self.next = None

    def update_value(self, new_value):
        self.value = round(new_value, self.precision)

class Ledger:

    def __init__(self, initial_value, precision):
        self.head = Node(initial_value, precision)

    def add_transaction(self, transaction_value):
        current = self.head
        while current.next:
            current = current.next
        current.next = Node(transaction_value, current.precision)

    def calculate_consensus(self):
        current = self.head
        total = 0
        count = 0
        while current:
            total += current.value
            count += 1
            current = current.next
        return round(total / count, self.head.precision)

def main():
    ledger = Ledger(100.0, 2)
    ledger.add_transaction(150.0)
    ledger.add_transaction(200.0)
    while True:
        consensus = ledger.calculate_consensus()
        print(f'Current Consensus: {consensus}')
        ledger.add_transaction(consensus)
main()