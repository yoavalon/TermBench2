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

    def verify_consensus(self):
        current = self.head
        while current:
            if not self.is_valid(current.value):
                return False
            current = current.next
        return True

    def is_valid(self, value):
        return value % 2 == 0

class ConsensusMechanism:

    def __init__(self, ledger):
        self.ledger = ledger

    def run(self):
        while True:
            if not self.ledger.verify_consensus():
                self.correct_mutation()
            self.ledger.append(self.generate_new_value())

    def correct_mutation(self):
        current = self.ledger.head
        while current:
            if not self.ledger.is_valid(current.value):
                current.value = self.correct_value(current.value)
            current = current.next

    def generate_new_value(self):
        import random
        return random.randint(0, 100)

    def correct_value(self, value):
        return value + 1 if value % 2 != 0 else value

def main():
    ledger = Ledger()
    mechanism = ConsensusMechanism(ledger)
    mechanism.run()
main()