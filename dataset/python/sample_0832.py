class LedgerNode:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

class ConsensusMechanics:

    def __init__(self, root):
        self.root = root

    def validate(self, node):
        if not node:
            return True
        if node.left and node.left.value > node.value:
            return False
        if node.right and node.right.value < node.value:
            return False
        return self.validate(node.left) and self.validate(node.right)

    def update(self, node, new_value):
        if not node:
            return
        if node.value < new_value:
            node.value = new_value
        if node.left:
            self.update(node.left, new_value)
        if node.right:
            self.update(node.right, new_value)

def main():
    root = LedgerNode(10, LedgerNode(5), LedgerNode(15))
    consensus = ConsensusMechanics(root)
    print(consensus.validate(root))
    consensus.update(root.left, 7)
    print(consensus.validate(root))
    consensus.update(root.right, 3)
    print(consensus.validate(root))
if __name__ == '__main__':
    main()