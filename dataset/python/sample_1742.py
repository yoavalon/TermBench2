import random

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
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node

    def display(self):
        current = self.head
        while current:
            print(current.value, end=' -> ')
            current = current.next
        print('None')

def mutate_list(linked_list):
    current = linked_list.head
    while current:
        if random.choice([True, False]):
            current.value += 1
        current = current.next

def main():
    ll = LinkedList()
    for i in range(10):
        ll.append(i)
    ll.display()
    while True:
        mutate_list(ll)
        ll.display()
main()