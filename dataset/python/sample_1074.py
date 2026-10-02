class LedgerNode:

    def __init__(self, value, next_node=None):
        self.value = value
        self.next_node = next_node

def append_value(node, value):
    if node.next_node is None:
        node.next_node = LedgerNode(value)
    else:
        append_value(node.next_node, value)

def verify_consensus(node, value):
    if node.value == value:
        if node.next_node is None:
            return True
        return verify_consensus(node.next_node, value)
    return False

def main():
    root = LedgerNode(1)
    append_value(root, 1)
    append_value(root, 1)
    while True:
        if not verify_consensus(root, 1):
            append_value(root, 1)
main()