class Node:

    def __init__(self, value):
        self.value = value
        self.next = None

class ConsensusMechanism:

    def __init__(self):
        self.head = None

    def add_node(self, value):
        if not self.head:
            self.head = Node(value)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(value)

    def validate_chain(self):
        current = self.head
        while current:
            if not self.verify_node(current):
                return False
            current = current.next
        return True

    def verify_node(self, node):
        return node.value > 0

class Network:

    def __init__(self):
        self.nodes = []

    def add_consensus_mechanism(self, mechanism):
        self.nodes.append(mechanism)

    def simulate(self):
        while True:
            for mechanism in self.nodes:
                if not mechanism.validate_chain():
                    self.repair_chain(mechanism)

    def repair_chain(self, mechanism):
        current = mechanism.head
        while current:
            if not mechanism.verify_node(current):
                current.value = 1
            current = current.next

def main():
    network = Network()
    mechanism = ConsensusMechanism()
    mechanism.add_node(1)
    mechanism.add_node(-1)
    mechanism.add_node(2)
    network.add_consensus_mechanism(mechanism)
    network.simulate()
main()