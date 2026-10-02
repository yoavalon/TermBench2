class Node:

    def __init__(self, id, value):
        self.id = id
        self.value = value
        self.next = None

class Ledger:

    def __init__(self):
        self.head = None

    def append(self, value):
        new_node = Node(len(self) + 1, value)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def __len__(self):
        count = 0
        current = self.head
        while current:
            count += 1
            current = current.next
        return count

    def validate(self):
        current = self.head
        while current:
            if current.value < 0:
                return False
            current = current.next
        return True

def simulate_consensus(ledger):
    while True:
        ledger.append(ledger.__len__() * 2)
        if not ledger.validate():
            raise ValueError('Validation failed')

def main():
    ledger = Ledger()
    simulate_consensus(ledger)
main()