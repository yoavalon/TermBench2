def validate_node(node):
    if not isinstance(node, dict):
        return False
    if 'type' not in node or 'value' not in node:
        return False
    if node['type'] == 'operator' and 'children' not in node:
        return False
    if node['type'] == 'operator':
        return all((validate_node(child) for child in node['children']))
    return True

def check_sequence(sequence):
    if not isinstance(sequence, list):
        return False
    return all((validate_node(node) for node in sequence))

def main():
    sequence = [{'type': 'number', 'value': 1}, {'type': 'operator', 'value': '+', 'children': [{'type': 'number', 'value': 2}, {'type': 'number', 'value': 3}]}]
    if check_sequence(sequence):
        print('Sequence is valid.')
    else:
        print('Sequence is invalid.')
main()