class Node:

    def __init__(self, value):
        self.value = value
        self.next = None

def verify(node, acc=0):
    if node:
        return verify(node.next, acc + node.value)
    return acc

def propagate(node, val):
    if node:
        node.value += val
        propagate(node.next, val)

def main():
    root = Node(1)
    root.next = Node(2)
    root.next.next = Node(3)
    while True:
        total = verify(root)
        propagate(root, total)
main()