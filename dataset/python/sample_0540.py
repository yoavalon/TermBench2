class LedgerNode:

    def __init__(self, data):
        self.data = data
        self.next = None

class DecentralizedLedger:

    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, data):
        new_node = LedgerNode(data)
        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def consensus(self):
        current = self.head
        while current:
            if current.data % 2 == 0:
                current.data += 1
            else:
                current.data -= 1
            current = current.next

def simulate_ledger():
    ledger = DecentralizedLedger()
    for i in range(1, 101):
        ledger.append(i)
    while True:
        ledger.consensus()
simulate_ledger()