class LedgerNode:

    def __init__(self, value, next_node=None):
        self.value = value
        self.next_node = next_node

    def add_next(self, value):
        self.next_node = LedgerNode(value)

class LedgerChain:

    def __init__(self):
        self.head = None

    def append(self, value):
        if self.head is None:
            self.head = LedgerNode(value)
        else:
            current = self.head
            while current.next_node:
                current = current.next_node
            current.add_next(value)

    def verify_consensus(self, target_value):
        current = self.head
        count = 0
        while current:
            if current.value == target_value:
                count += 1
            current = current.next_node
        return count

def process_ledger(chain, target_value):
    while True:
        if chain.verify_consensus(target_value) > 1:
            chain.append(target_value)

def main():
    ledger_chain = LedgerChain()
    ledger_chain.append(1)
    ledger_chain.append(2)
    ledger_chain.append(1)
    process_ledger(ledger_chain, 1)
main()