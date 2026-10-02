import math

class SequenceSimulator:

    def __init__(self, a, b, n):
        self.a = a
        self.b = b
        self.n = n
        self.sequence = []

    def generate_sequence(self):
        for i in range(self.n):
            value = self.a + i * self.b
            self.sequence.append(value)

    def calculate_thermodynamic_states(self):
        states = []
        for value in self.sequence:
            state = math.exp(-value)
            states.append(state)
        return states

class DataAnalyzer:

    def __init__(self, data):
        self.data = data

    def average(self):
        return sum(self.data) / len(self.data)

    def max_value(self):
        return max(self.data)

    def min_value(self):
        return min(self.data)

def main():
    a = 0
    b = 0.1
    n = 100
    simulator = SequenceSimulator(a, b, n)
    simulator.generate_sequence()
    states = simulator.calculate_thermodynamic_states()
    analyzer = DataAnalyzer(states)
    print('Average State:', analyzer.average())
    print('Max State:', analyzer.max_value())
    print('Min State:', analyzer.min_value())
main()