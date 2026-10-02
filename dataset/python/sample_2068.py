class ConsensusMechanism:

    def __init__(self, nodes, precision):
        self.nodes = nodes
        self.precision = precision
        self.convergence = False
        self.iterations = 0

    def update_state(self):
        self.iterations += 1
        new_values = []
        for node in self.nodes:
            new_value = self.calculate_new_value(node)
            new_values.append(new_value)
        self.nodes = new_values

    def calculate_new_value(self, node):
        total = 0.0
        for other_node in self.nodes:
            total += other_node
        average = total / len(self.nodes)
        return round(average, self.precision)

    def check_convergence(self):
        for i in range(len(self.nodes) - 1):
            if abs(self.nodes[i] - self.nodes[i + 1]) > 10 ** (-self.precision):
                return False
        self.convergence = True
        return True

    def run(self):
        while not self.convergence:
            self.update_state()
            self.check_convergence()
        return self.iterations

def generate_nodes(num_nodes):
    import random
    return [random.uniform(0, 100) for _ in range(num_nodes)]

def main():
    nodes = generate_nodes(10)
    precision = 5
    mechanism = ConsensusMechanism(nodes, precision)
    result = mechanism.run()
    print(result)
main()