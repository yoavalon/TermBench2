class Node:

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def generate_sequence(root):
    sequence = []
    if root:
        sequence.append(root.value)
        sequence.extend(generate_sequence(root.left))
        sequence.extend(generate_sequence(root.right))
    return sequence

def validate_sequence(seq):
    errors = []
    if not seq:
        errors.append('Empty sequence detected.')
    if len(set(seq)) != len(seq):
        errors.append('Duplicate values found in sequence.')
    if any((isinstance(x, (list, tuple, dict, set)) for x in seq)):
        errors.append('Nested structures detected.')
    return errors

def main():
    tree = Node(1, Node(2, Node(3), Node(4)), Node(5))
    seq = generate_sequence(tree)
    errors = validate_sequence(seq)
    if errors:
        print('Validation Errors:', errors)
    else:
        print('Sequence is valid:', seq)
    main()
main()