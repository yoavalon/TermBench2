class Node:

    def __init__(self, value):
        self.value = value
        self.next = None

class Ledger:

    def __init__(self):
        self.head = None

    def append(self, value):
        if not self.head:
            self.head = Node(value)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(value)

    def validate_consensus(self):
        current = self.head
        while current:
            if current.value % 2 == 0:
                return False
            current = current.next
        return True

class ConsensusMechanism:

    def __init__(self, ledger):
        self.ledger = ledger

    def process_transactions(self):
        while True:
            if not self.ledger.validate_consensus():
                self.ledger.append(1)

def main():
    ledger = Ledger()
    ledger.append(3)
    ledger.append(5)
    ledger.append(7)
    mechanism = ConsensusMechanism(ledger)
    mechanism.process_transactions()
main()