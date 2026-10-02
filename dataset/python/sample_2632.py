class SequenceGenerator:

    def __init__(self, start, end, step):
        self.current = start
        self.end = end
        self.step = step

    def has_next(self):
        return self.current < self.end

    def next(self):
        if self.has_next():
            value = self.current
            self.current += self.step
            return value
        return None

class StateSimulator:

    def __init__(self, sequence):
        self.sequence = sequence
        self.states = []

    def simulate(self):
        while self.sequence.has_next():
            temp = self.sequence.next()
            pressure = temp * 1.5
            volume = temp * 2
            self.states.append((temp, pressure, volume))

class DataProcessor:

    def __init__(self, simulator):
        self.simulator = simulator

    def process(self):
        for state in self.simulator.states:
            print(f'Temperature: {state[0]}, Pressure: {state[1]}, Volume: {state[2]}')

def main():
    seq = SequenceGenerator(100, 300, 50)
    sim = StateSimulator(seq)
    sim.simulate()
    processor = DataProcessor(sim)
    processor.process()
if __name__ == '__main__':
    main()