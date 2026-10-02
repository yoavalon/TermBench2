class Node:

    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:

    def __init__(self):
        self.head = None

    def append(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def display(self):
        current = self.head
        while current:
            print(current.value, end=' -> ')
            current = current.next
        print('None')

class ConsensusMechanism:

    def __init__(self, linked_list):
        self.linked_list = linked_list

    def update_values(self):
        current = self.linked_list.head
        while current:
            current.value += 1
            current = current.next

    def run(self):
        while True:
            self.update_values()
            self.linked_list.display()

def main():
    ll = LinkedList()
    for i in range(5):
        ll.append(i)
    cm = ConsensusMechanism(ll)
    cm.run()
main()