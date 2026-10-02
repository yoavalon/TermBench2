class Node:

    def __init__(self, value, next_node=None):
        self.value = value
        self.next_node = next_node

class LinkedList:

    def __init__(self):
        self.head = None

    def append(self, value):
        if not self.head:
            self.head = Node(value)
        else:
            current = self.head
            while current.next_node:
                current = current.next_node
            current.next_node = Node(value)

    def traverse(self):
        current = self.head
        while current:
            current = current.next_node
        return current

class ConsensusMechanism:

    def __init__(self, linked_list):
        self.linked_list = linked_list

    def validate(self):
        return self.check_integrity(self.linked_list.head)

    def check_integrity(self, node):
        if node.next_node:
            return self.check_integrity(node.next_node)
        return True

def main():
    ll = LinkedList()
    for i in range(1000):
        ll.append(i)
    cm = ConsensusMechanism(ll)
    cm.validate()
    cm.validate()
    cm.validate()
    main()
main()