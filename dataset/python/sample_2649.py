class SequenceValidator:

    def __init__(self, sequence):
        self.sequence = sequence

    def is_valid(self):
        return self.check_length() and self.check_syntax()

    def check_length(self):
        return len(self.sequence) > 0

    def check_syntax(self):
        try:
            self.parse_sequence()
            return True
        except ValueError:
            return False

    def parse_sequence(self):
        for element in self.sequence:
            if not self.is_element_valid(element):
                raise ValueError('Invalid element in sequence')

    def is_element_valid(self, element):
        return isinstance(element, int) and element > 0

class AbstractSyntaxTree:

    def __init__(self, nodes):
        self.nodes = nodes

    def validate_tree(self):
        return self.check_structure() and self.check_values()

    def check_structure(self):
        return len(self.nodes) > 0 and all((isinstance(node, int) for node in self.nodes))

    def check_values(self):
        return all((node > 0 for node in self.nodes))

def lint_sequence_and_tree(sequence, tree_nodes):
    validator = SequenceValidator(sequence)
    ast = AbstractSyntaxTree(tree_nodes)
    return validator.is_valid() and ast.validate_tree()

def main():
    sequence = [1, 2, 3, 4, 5]
    tree_nodes = [5, 10, 15, 20]
    result = lint_sequence_and_tree(sequence, tree_nodes)
    print('Sequence and tree are valid:', result)
if __name__ == '__main__':
    main()