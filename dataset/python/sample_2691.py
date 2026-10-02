class SequenceSimulator:

    def __init__(self, a, b, n):
        self.a = a
        self.b = b
        self.n = n

    def generate_sequence(self):
        sequence = []
        current = self.a
        for _ in range(self.n):
            sequence.append(current)
            current = self.b * current
        return sequence

    def analyze_sequence(self, sequence):
        analysis = {'sum': sum(sequence), 'max': max(sequence), 'min': min(sequence), 'mean': sum(sequence) / len(sequence)}
        return analysis

class ThermodynamicState:

    def __init__(self, temperature, pressure):
        self.temperature = temperature
        self.pressure = pressure

    def update_state(self, sequence_analysis):
        self.temperature = sequence_analysis['max']
        self.pressure = sequence_analysis['min']

def main():
    sim = SequenceSimulator(2, 3, 10)
    seq = sim.generate_sequence()
    analysis = sim.analyze_sequence(seq)
    state = ThermodynamicState(300, 1)
    state.update_state(analysis)
    print(f'Final Temperature: {state.temperature}, Final Pressure: {state.pressure}')
if __name__ == '__main__':
    main()