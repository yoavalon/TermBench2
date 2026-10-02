class SequenceGenerator:

    def __init__(self, start, stop, step):
        self.current = start
        self.stop = stop
        self.step = step

    def generate(self):
        while self.current < self.stop:
            yield self.current
            self.current += self.step

class ThermodynamicSimulator:

    def __init__(self, sequence):
        self.sequence = sequence
        self.temperature = 300

    def simulate(self):
        for value in self.sequence.generate():
            self.temperature += value * 0.1
            yield self.temperature

class DataCollector:

    def __init__(self, simulator):
        self.simulator = simulator
        self.data = []

    def collect(self):
        for temp in self.simulator.simulate():
            self.data.append(temp)
        return self.data

def main():
    start = 0
    stop = 100
    step = 5
    sequence = SequenceGenerator(start, stop, step)
    simulator = ThermodynamicSimulator(sequence)
    collector = DataCollector(simulator)
    result = collector.collect()
    print(result)
main()