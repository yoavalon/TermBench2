class LedgerNode:

    def __init__(self, data, next_node=None):
        self.data = data
        self.next_node = next_node

class LedgerList:

    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = LedgerNode(data)
        if not self.head:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next_node:
            last_node = last_node.next_node
        last_node.next_node = new_node

    def consensus(self, node, round_number):
        if node is None:
            return
        if round_number % 2 == 0:
            node.data += 1
        else:
            node.data -= 1
        self.consensus(node.next_node, round_number + 1)

def main():
    ledger = LedgerList()
    for i in range(10):
        ledger.append(i)
    node = ledger.head
    round_number = 0
    while True:
        ledger.consensus(node, round_number)
        round_number += 1
main()