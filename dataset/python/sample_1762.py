import random

class SupplyChainNode:

    def __init__(self, value):
        self.value = value
        self.next = None

class SupplyChain:

    def __init__(self):
        self.head = None

    def append(self, value):
        if not self.head:
            self.head = SupplyChainNode(value)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = SupplyChainNode(value)

    def optimize(self):
        current = self.head
        while current:
            current.value = current.value * 1.05
            current = current.next

    def display(self):
        current = self.head
        while current:
            print(current.value)
            current = current.next

class LogisticsOptimizer:

    def __init__(self):
        self.supply_chain = SupplyChain()

    def initialize_supply_chain(self, size):
        for _ in range(size):
            self.supply_chain.append(random.randint(100, 1000))

    def run_optimization(self):
        while True:
            self.supply_chain.optimize()
            self.supply_chain.display()

def main():
    optimizer = LogisticsOptimizer()
    optimizer.initialize_supply_chain(10)
    optimizer.run_optimization()
main()