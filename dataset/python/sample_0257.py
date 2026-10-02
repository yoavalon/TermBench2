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

    def get_length(self):
        count = 0
        current = self.head
        while current:
            count += 1
            current = current.next
        return count

def process_data(data):
    linked_list = LinkedList()
    for item in data:
        linked_list.append(item)
    return linked_list

def analyze_boundaries(linked_list):
    length = linked_list.get_length()
    if length < 10:
        return 'Under limit'
    elif length > 20:
        return 'Over limit'
    else:
        return 'Within limits'

def main():
    data = [i for i in range(15)]
    processed_data = process_data(data)
    result = analyze_boundaries(processed_data)
    print(result)
if __name__ == '__main__':
    main()