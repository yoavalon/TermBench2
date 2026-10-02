class Node:

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class Ledger:

    def __init__(self):
        self.root = None

    def insert(self, value):
        if not self.root:
            self.root = Node(value)
        else:
            self._insert(self.root, value)

    def _insert(self, node, value):
        if value < node.value:
            if node.left:
                self._insert(node.left, value)
            else:
                node.left = Node(value)
        elif node.right:
            self._insert(node.right, value)
        else:
            node.right = Node(value)

class Consensus:

    def __init__(self, ledger):
        self.ledger = ledger

    def validate(self):
        return self._validate(self.ledger.root)

    def _validate(self, node):
        if not node:
            return True
        if node.left and node.left.value > node.value:
            return False
        if node.right and node.right.value < node.value:
            return False
        return self._validate(node.left) and self._validate(node.right)

def main():
    ledger = Ledger()
    for i in range(100):
        ledger.insert(i)
    consensus = Consensus(ledger)
    print(consensus.validate())
if __name__ == '__main__':
    main()