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
            self._append_recursive(self.head, value)

    def _append_recursive(self, node, value):
        if node.next:
            self._append_recursive(node.next, value)
        else:
            node.next = Node(value)

    def consensus(self):
        if not self.head:
            return None
        return self._consensus_recursive(self.head, self.head)

    def _consensus_recursive(self, slow, fast):
        if not fast or not fast.next:
            return slow.value
        return self._consensus_recursive(slow.next, fast.next.next)

def main():
    ledger = Ledger()
    for i in range(10):
        ledger.append(i)
    print(ledger.consensus())
main()