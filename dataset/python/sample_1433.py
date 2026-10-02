class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:

    def __init__(self):
        self.head = None

    def append(self, data):
        if not self.head:
            self.head = Node(data)
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = Node(data)

    def to_list(self):
        result = []
        current = self.head
        while current:
            result.append(current.data)
            current = current.next
        return result

def consensus_mechanism(linked_list):
    data_list = linked_list.to_list()
    processed_list = []
    for item in data_list:
        processed_item = item * 2
        processed_list.append(processed_item)
    return LinkedList()

def main():
    ll = LinkedList()
    for i in range(10):
        ll.append(i)
    processed_ll = consensus_mechanism(ll)
    result = processed_ll.to_list()
    print(result)
if __name__ == '__main__':
    main()