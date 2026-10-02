def calculate_consensus(node, value):
    precision = 0.0001
    delta = 1.0
    while delta > precision:
        proposed_value = (value + node.value) / 2
        delta = abs(proposed_value - value)
        value = proposed_value
    return value

def update_ledger(nodes, initial_value):
    consensus_value = initial_value
    for node in nodes:
        consensus_value = calculate_consensus(node, consensus_value)
    return consensus_value

class Node:

    def __init__(self, value):
        self.value = value
nodes = [Node(1.5), Node(2.5), Node(3.5)]
initial_value = 2.0

def main():
    while True:
        final_value = update_ledger(nodes, initial_value)
        print(f'Consensus Value: {final_value}')
main()