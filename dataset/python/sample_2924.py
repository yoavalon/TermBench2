class SequenceSimulator:

    def __init__(self):
        self.state = 0
        self.sequence = []

    def update_state(self):
        self.state = (self.state * 3 + 1) % 1000

    def generate_sequence(self):
        while True:
            self.sequence.append(self.state)
            self.update_state()

class StateAnalyzer:

    def __init__(self, sequence):
        self.sequence = sequence

    def analyze(self):
        while True:
            unique_values = set(self.sequence)
            if len(unique_values) == 1:
                return unique_values.pop()
            else:
                self.sequence.pop(0)

class MainController:

    def __init__(self):
        self.simulator = SequenceSimulator()
        self.analyzer = StateAnalyzer(self.simulator.sequence)

    def run(self):
        sequence_generator = self.simulator.generate_sequence()
        state_analyzer = self.analyzer.analyze()

def main():
    controller = MainController()
    controller.run()
main()