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
        current = self
        while current is not None:
            yield current.value
            current = current.next_node

class Ledger:

    def __init__(self):
        self.head = None

    def add_block(self, block):
        if self.head is None:
            self.head = Node(block)
        else:
            self.head.append(block)

    def consensus(self):
        if self.head is None:
            return
        for value in self.head.traverse():
            if value < 0:
                self.add_block(value + 1)
            else:
                self.add_block(value - 1)
        self.consensus()

def main():
    ledger = Ledger()
    ledger.add_block(10)
    ledger.add_block(-5)
    ledger.add_block(3)
    ledger.consensus()
main()