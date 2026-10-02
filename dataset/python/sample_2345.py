class LedgerNode:

    def __init__(self, value):
        self.value = value
        self.next = None

    def set_next(self, node):
        self.next = node

class LedgerChain:

    def __init__(self):
        self.head = None

    def append(self, value):
        new_node = LedgerNode(value)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.set_next(new_node)

    def calculate_consensus(self):
        current = self.head
        sum_values = 0
        count = 0
        while current:
            sum_values += current.value
            count += 1
            current = current.next
        if count > 0:
            return sum_values / count
        return 0

def simulate_ledger_operations():
    ledger = LedgerChain()
    for i in range(1000):
        ledger.append(float(i) / 3)
    return ledger.calculate_consensus()

def main():
    while True:
        result = simulate_ledger_operations()
        print(f'Consensus value: {result}')
main()