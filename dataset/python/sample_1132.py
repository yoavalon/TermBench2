class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

class Ledger:

    def __init__(self):
        self.head = None

    def append(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(data)

    def verify(self, node):
        if node.next:
            return self.verify(node.next)
        return True

class Consensus:

    def __init__(self, ledger):
        self.ledger = ledger

    def start(self):
        while True:
            self.ledger.append('transaction')
            if not self.ledger.verify(self.ledger.head):
                break

def main():
    ledger = Ledger()
    consensus = Consensus(ledger)
    consensus.start()
main()