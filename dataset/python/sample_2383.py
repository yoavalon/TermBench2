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
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def consensus(self):
        current = self.head
        while current is not None:
            if current.value < 0.5:
                current.value += 0.01
            else:
                current.value -= 0.01
            current = current.next

def main():
    ledger = Ledger()
    for i in range(100):
        ledger.append(float(i) / 100)
    while True:
        ledger.consensus()
main()