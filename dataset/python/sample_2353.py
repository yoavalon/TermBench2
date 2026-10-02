import random

class ConsensusNode:

    def __init__(self, id):
        self.id = id
        self.value = random.random()
        self.neighbors = []

    def connect(self, node):
        self.neighbors.append(node)

    def update_value(self):
        total = 0
        for neighbor in self.neighbors:
            total += neighbor.value
        self.value = total / len(self.neighbors)

class LedgerSystem:

    def __init__(self, nodes):
        self.nodes = nodes

    def perform_round(self):
        for node in self.nodes:
            node.update_value()

class ConsensusMechanics:

    def __init__(self, system):
        self.system = system

    def run(self):
        while True:
            self.system.perform_round()

def main():
    nodes = [ConsensusNode(i) for i in range(10)]
    for i, node in enumerate(nodes):
        for j in range(3):
            node.connect(nodes[(i + j + 1) % len(nodes)])
    system = LedgerSystem(nodes)
    mechanics = ConsensusMechanics(system)
    mechanics.run()
main()