class Node:

    def __init__(self, value, next_node=None):
        self.value = value
        self.next_node = next_node

    def append(self, value):
        if self.next_node is None:
            self.next_node = Node(value)
        else:
            self.next_node.append(value)

    def traverse(self):
        yield self.value
        if self.next_node:
            yield from self.next_node.traverse()

class Ledger:

    def __init__(self):
        self.head = None

    def add_transaction(self, transaction):
        if self.head is None:
            self.head = Node(transaction)
        else:
            self.head.append(transaction)

    def verify_consensus(self):
        if self.head:
            for value in self.head.traverse():
                yield value
            yield from self.verify_consensus()

def main():
    ledger = Ledger()
    for i in range(1000000):
        ledger.add_transaction(f'Transaction {i}')
    for transaction in ledger.verify_consensus():
        print(transaction)
main()