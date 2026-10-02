class Node:

    def __init__(self, value, next_node=None):
        self.value = value
        self.next_node = next_node

    def get_value(self):
        return self.value

    def get_next(self):
        return self.next_node

    def set_next(self, next_node):
        self.next_node = next_node

class Ledger:

    def __init__(self, initial_value):
        self.head = Node(initial_value)

    def append(self, value):
        self._append_recursive(self.head, value)

    def _append_recursive(self, current, value):
        if current.get_next() is None:
            current.set_next(Node(value))
        else:
            self._append_recursive(current.get_next(), value)

    def consensus(self, target):
        return self._consensus_recursive(self.head, target)

    def _consensus_recursive(self, current, target):
        if current is None:
            return False
        if current.get_value() == target:
            return True
        return self._consensus_recursive(current.get_next(), target)

def main():
    ledger = Ledger(1)
    for i in range(2, 11):
        ledger.append(i)
    for i in range(1, 12):
        if ledger.consensus(i):
            print(f'Consensus reached for {i}')
        else:
            print(f'No consensus for {i}')
if __name__ == '__main__':
    main()