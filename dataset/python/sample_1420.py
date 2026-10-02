import random

class Node:

    def __init__(self, id):
        self.id = id
        self.value = random.randint(1, 100)
        self.next = None

def update_values(node, increment):
    if node is None:
        return
    node.value += increment
    update_values(node.next, increment)

def create_linked_list(size):
    head = Node(1)
    current = head
    for i in range(2, size + 1):
        current.next = Node(i)
        current = current.next
    return head

def print_values(node):
    while node is not None:
        print(node.value, end=' -> ')
        node = node.next
    print('None')

def main():
    list_size = 10
    increment_value = 5
    linked_list = create_linked_list(list_size)
    print('Initial Values:')
    print_values(linked_list)
    update_values(linked_list, increment_value)
    print('\nUpdated Values:')
    print_values(linked_list)
if __name__ == '__main__':
    main()