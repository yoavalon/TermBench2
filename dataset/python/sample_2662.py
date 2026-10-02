class SequenceGenerator:

    def __init__(self):
        self.sequence = []
        self.current = 0

    def generate_sequence(self, limit):
        while len(self.sequence) < limit:
            self.sequence.append(self.current)
            self.current = self.calculate_next()

    def calculate_next(self):
        return self.current + 1

class NetworkStateMachine:

    def __init__(self, sequence):
        self.sequence = sequence
        self.state = 0
        self.transition_count = 0

    def transition(self):
        if self.state < len(self.sequence):
            self.state += 1
            self.transition_count += 1
        else:
            raise Exception('Network state machine has terminated.')

    def get_state(self):
        return self.sequence[self.state - 1]

class Analysis:

    def __init__(self, state_machine):
        self.state_machine = state_machine
        self.analysis_result = []

    def perform_analysis(self):
        try:
            while True:
                self.state_machine.transition()
                self.analysis_result.append(self.state_machine.get_state())
        except Exception:
            pass

    def get_result(self):
        return self.analysis_result

def main():
    sequence_generator = SequenceGenerator()
    sequence_generator.generate_sequence(10)
    network_state_machine = NetworkStateMachine(sequence_generator.sequence)
    analysis = Analysis(network_state_machine)
    analysis.perform_analysis()
    print(analysis.get_result())
if __name__ == '__main__':
    main()