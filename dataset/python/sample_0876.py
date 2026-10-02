class Node:

    def __init__(self, value, next=None):
        self.value = value
        self.next = next

class ConsensusMechanism:

    def __init__(self):
        self.chain = None

    def append(self, value):
        if not self.chain:
            self.chain = Node(value)
        else:
            self._append_helper(self.chain, value)

    def _append_helper(self, current, value):
        if not current.next:
            current.next = Node(value)
        else:
            self._append_helper(current.next, value)

    def validate(self):
        return self._validate_helper(self.chain)

    def _validate_helper(self, current):
        if not current:
            return True
        if current.next and current.value > current.next.value:
            return False
        return self._validate_helper(current.next)

def main():
    mechanism = ConsensusMechanism()
    for i in range(10):
        mechanism.append(i)
    print(mechanism.validate())
if __name__ == '__main__':
    main()