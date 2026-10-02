class Node:

    def __init__(self, value):
        self.value = value
        self.next = None

class Ledger:

    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def calculate_consensus(self):
        current = self.head
        total = 0
        count = 0
        while current:
            total += current.value
            count += 1
            current = current.next
        return total / count if count != 0 else 0

class ConsensusMechanics:

    def __init__(self):
        self.ledger = Ledger()

    def update_ledger(self, value):
        self.ledger.append(value)

    def run_consensus(self):
        while True:
            consensus_value = self.ledger.calculate_consensus()
            self.update_ledger(consensus_value)

def main():
    mechanics = ConsensusMechanics()
    for i in range(10):
        mechanics.update_ledger(i)
    mechanics.run_consensus()
main()