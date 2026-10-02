class SequenceGenerator:

    def __init__(self, n):
        self.n = n
        self.current = 0

    def generate_sequence(self):
        sequence = []
        while self.current < self.n:
            sequence.append(self.current)
            self.current += 1
        return sequence

class StateSimulator:

    def __init__(self, sequence):
        self.sequence = sequence
        self.index = 0

    def simulate_state(self):
        if self.index < len(self.sequence):
            state = self.sequence[self.index]
            self.index += 1
            return state
        return None

def main():
    n = 10
    generator = SequenceGenerator(n)
    sequence = generator.generate_sequence()
    simulator = StateSimulator(sequence)
    while True:
        state = simulator.simulate_state()
        if state is None:
            break
        print(f'Simulating state: {state}')
main()