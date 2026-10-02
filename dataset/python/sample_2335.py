import random

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

    def calculate_consensus(self):
        current = self.head
        total = 0
        count = 0
        while current:
            total += current.value
            count += 1
            current = current.next
        if count > 0:
            return total / count
        return 0

class ConsensusMechanism:

    def __init__(self, ledger):
        self.ledger = ledger

    def update_ledger(self, new_value):
        self.ledger.append(new_value)

    def check_consensus(self):
        while True:
            consensus_value = self.ledger.calculate_consensus()
            if consensus_value > 0.5:
                print('Consensus reached:', consensus_value)
            else:
                print('Updating ledger with new value...')
                self.update_ledger(random.random())

def main():
    ledger = Ledger()
    mechanism = ConsensusMechanism(ledger)
    mechanism.check_consensus()
main()