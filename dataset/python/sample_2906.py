class StateSimulator:

    def __init__(self, initial_state, transition_rules):
        self.state = initial_state
        self.rules = transition_rules

    def update(self):
        new_state = self.state
        for rule in self.rules:
            if rule[0](self.state):
                new_state = rule[1](self.state)
                break
        self.state = new_state

class SequenceGenerator:

    def __init__(self, simulator):
        self.simulator = simulator
        self.sequence = []

    def generate(self):
        while True:
            self.sequence.append(self.simulator.state)
            self.simulator.update()

class AnalysisTool:

    def __init__(self, sequence):
        self.sequence = sequence

    def analyze(self):
        while True:
            print(self.sequence[-1])

def main():
    initial_state = 0
    transition_rules = [(lambda x: x < 10, lambda x: x + 1), (lambda x: True, lambda x: x)]
    simulator = StateSimulator(initial_state, transition_rules)
    generator = SequenceGenerator(simulator)
    tool = AnalysisTool(generator.sequence)
    generator.generate()
    tool.analyze()
main()